#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;


//проверка работы конструктора без параметров
TEST(FunctionTests, FuncConstructorCommonGet) {
    Function a;
    EXPECT_EQ(a.get_type(), Type::power);
    EXPECT_EQ(a.get_a(), 0);
    EXPECT_EQ(a.get_x(), 0);
    EXPECT_EQ(a.get_b(), 0);
    EXPECT_EQ(a.get_c(), 0);
}

TEST(FunctionTests, power_ComputeValue) {
    Function power1(1, 2, 3);
    EXPECT_EQ(power1.get_type(), Type::power);
    EXPECT_EQ(power1.get_a(), 1);
    EXPECT_EQ(power1.get_x(), 2);
    EXPECT_EQ(power1.get_b(), 3);
    EXPECT_EQ(power1.compute_value(), 8);
}

TEST(FunctionTests, log_ComputeValue) {
    Function log1(1, -2);
    EXPECT_EQ(log1.get_type(), Type::log);
    EXPECT_EQ(log1.get_c(), 1);
    EXPECT_EQ(log1.get_x(), -2);
    EXPECT_NEAR(log1.compute_value(), 0.693, 0.001f);
}


TEST(FunctionTests, power_Compute_derivative) {
    Function power2(1, 2, 3);
    EXPECT_EQ(power2.compute_derivative(), 12);
}

TEST(FunctionTests, log_Compute_derivative) {
    Function log2(1, 2);
    EXPECT_EQ(log2.compute_derivative(), 0.5);
}


TEST(FunctionTests, power_Compute_antiderivative) {
    Function power3(2, 2, 3);
    EXPECT_EQ(power3.compute_antiderivative(), 8);
}

TEST(FunctionTests, log_Compute_antiderivative) {
    Function log3(2, 2);
    EXPECT_NEAR(log3.compute_antiderivative(), -1.228, 0.001f);
}
TEST(ContainerTests, ContainerTestConstructor2) {
    Function a1 = Function(1, 7);
    Function a2 = Function(3, 2);
    Function a3 = Function(3, 1, 4);
    Function s[] = { a1, a2, a2 ,a2, a3, a3 ,a3 ,a3 };
    Container a = Container(s, 9);
    EXPECT_EQ(a[7].compute_value(), 3);
    EXPECT_EQ(a.get_size(), 9);
}

TEST(ContainerTests, ContainerGetSize) {
    Container a;
    EXPECT_EQ(a.get_size(), 5);
}

TEST(ContainerTests, ContainerTestOperator1) {
    Container a;
    EXPECT_EQ(a[0].get_a(), Function().get_a());
}

TEST(ContainerTests, ContainerTestOperator2) {
    Container a;
    Function a1 = Function(1, 3);
    Function a2 = Function(1, 2);
    Function a3 = Function(3, 1, 4);
    a[0] = a1;
    a[1] = a2;
    a[2] = a3;
    EXPECT_EQ(a[0].get_c(), a1.get_c());
    EXPECT_EQ(a[1].get_a(), a2.get_a());
    EXPECT_EQ(a[2].get_a(), a3.get_a());
}

TEST(ContainerTests, ContainerTestAppendel) {
    Container a;
    Function a1(1, 8, 1), a2(3, 2);
    a.appendel(1, a1);
    a.appendel(2, a2);
    EXPECT_EQ(a[0].get_a(), Function().get_a());
    EXPECT_EQ(a[1].get_a(), a1.get_a());
    EXPECT_EQ(a[2].get_c(), a2.get_c());

}

TEST(ContainerTests, ContainerTestDelel) {
    Container a;
    Function a1 = Function(4, 3, 1), a2 = Function(4, 3);
    a.appendel(1, a1);
    a.appendel(5, a2);
    a.dellel(5);
    EXPECT_EQ(a[0].get_a(), Function().get_a());
    EXPECT_EQ(a[1].get_a(), a1.get_a());
    // EXPECT_EQ(a[5].get_c(), a2.get_c()); - тест провалится, элемент удален!
}

TEST(ContainerTests, ContainerTestFindMinDerivative) {
    Container a;
    Function a1(1, 2), a2(1, 2, 3), a3(2, 3), a4(2, 3, 4), a5(3, 4, 5); 
    // (2*ln(1))'=2, (1*2^3)'=12, (3*ln(2))'=1,5, (2*3^4)'=72, (3*4*5)'=15*72
    a[0] = a1;
    a[1] = a2;
    a[2] = a3;
    a[3] = a4;
    a[4] = a5;
    Function res = a.find_min_derivative();
    EXPECT_EQ(res.get_c(), 1); // производная наим у а4 - логарифмю ф-ии
}