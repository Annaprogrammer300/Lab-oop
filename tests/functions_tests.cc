#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;
using namespace std;



//проверка работы конструктора без параметров
TEST(FunctionTests, FuncConstructorCommonGet) {
    Power a;
    Log c;
    FunctionList b;
    EXPECT_EQ(a.get_a(), 0);
    EXPECT_EQ(a.get_b(), 0);
    EXPECT_EQ(c.get_c(), 0);
    EXPECT_EQ(b.get_size(), 0);
}

TEST(FunctionTests, power_ComputeValue) {
    auto f = Power(2, 3);
    EXPECT_EQ(f.get_a(), 2);
    EXPECT_EQ(f.get_b(), 3);
    EXPECT_EQ(f.compute_value(2), 16);
}

TEST(FunctionTests, log_ComputeValue) {
    auto f = Log(1);
    EXPECT_EQ(f.get_c(), 1);
    EXPECT_NEAR(f.compute_value(-2), 0.693, 0.001f);
}


TEST(FunctionTests, power_Compute_derivative) {
    auto f = Power(2, 3);
    EXPECT_EQ(f.compute_derivative()->compute_value(2), 24);
}

TEST(FunctionTests, log_Compute_derivative) {
    auto f = Log(2);
    EXPECT_EQ(f.compute_derivative()->compute_value(2), 1);
}


TEST(FunctionTests, power_Compute_antiderivative) {
    auto f = Power(2,3);
    EXPECT_EQ(f.compute_antiderivative()->compute_value(2), 8);
}

TEST(FunctionTests, log_Compute_antiderivative) {
    auto f = Log(2);
    EXPECT_NEAR(f.compute_antiderivative()->compute_value(2), -1.228, 0.001f);
}



