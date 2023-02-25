#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;



TEST(FunctionTests, log_ComputeValue) {
    const auto log1 = Function::create_log(1);
    EXPECT_NEAR(log1.compute_value(1, 3), 0, E);
}