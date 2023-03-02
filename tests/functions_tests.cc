#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;



TEST(FunctionTests, log_ComputeValue) {
    Function power1(1, 2, 3);
    EXPECT_EQ(power1.get_type(), function::Type::power);
}