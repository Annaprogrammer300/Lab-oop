#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;
using namespace std;



//проверка работы конструктора без параметров
TEST(FunctionTests, FuncConstructorCommonGet) {
    Function a;
    FunctionList b;
    EXPECT_EQ(a.get_a(), 0);
    EXPECT_EQ(a.get_b(), 0);
    EXPECT_EQ(a.get_c(), 0);
    EXPECT_EQ(b.get_size(), 0);
}

TEST(FunctionTests, power_ComputeValue) {
    Function power1(Type::power, 2, 3);
    EXPECT_EQ(power1.get_f_type(), Type::power);
    EXPECT_EQ(power1.get_a(), 2);
    EXPECT_EQ(power1.get_b(), 3);
    EXPECT_EQ(power1.compute_value(2), 16);
}

TEST(FunctionTests, log_ComputeValue) {
    Function log1(Type::log, 1);
    EXPECT_EQ(log1.get_f_type(), Type::log);
    EXPECT_EQ(log1.get_c(), 1);
    EXPECT_NEAR(log1.compute_value(-2), 0.693, 0.001f);
}


TEST(FunctionTests, power_Compute_derivative) {
    Function power2(Type::power, 2, 3);
    Function vrem = power2.compute_derivative();
    EXPECT_EQ(vrem.compute_value(2), 24);
}

TEST(FunctionTests, log_Compute_derivative) {
    Function log2(Type::log, 2);
    Function vrem = log2.compute_derivative();
    EXPECT_EQ(vrem.compute_value(2), 1);
}


TEST(FunctionTests, power_Compute_antiderivative) {
    Function power3(Type::power, 2, 3);
    Function vrem = power3.compute_antiderivative();
    EXPECT_EQ(vrem.compute_value(2), 8);
}

TEST(FunctionTests, log_Compute_antiderivative) {
    Function log3(Type::log, 2);
    Function vrem = log3.compute_antiderivative();
    EXPECT_NEAR(vrem.compute_value(2), -1.228, 0.001f);
}



