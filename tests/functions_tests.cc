#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;



TEST(FunctionTests, power_ComputeValue) {
    Function power1(1, 2, 3);
    EXPECT_EQ(power1.compute_value(), 8);
}

TEST(FunctionTests, log_ComputeValue) {
    Function log1(1, 2);
    EXPECT_NEAR(log1.compute_value(), 0.693147, E);
}


TEST(FunctionTests, power_Compute_derivative) {
    Function power2(1, 2, 3);
    EXPECT_EQ(power2.get_type(), function::Type::power);
}

TEST(FunctionTests, log_Compute_derivative) {
    Function log2(1, 2);
    EXPECT_EQ(log2.get_type(), function::Type::log);
}


TEST(FunctionTests, power_Compute_antiderivative) {
    Function power3(1, 2, 3);
    EXPECT_EQ(power3.get_type(), function::Type::power);
}

TEST(FunctionTests, log_Compute_antiderivative) {
    Function log3(1, 2);
    EXPECT_EQ(log3.get_type(), function::Type::log);
}