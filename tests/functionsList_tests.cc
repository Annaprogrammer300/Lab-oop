#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;
using namespace std;

FunctionList construct() {
    FunctionList functions;
    auto f = Power(2, 3);
    auto f1 = Power(1, 3);
    auto f2 = Log(1);
    auto f3 = Log(2);

    functions.add(f.clone());
    functions.add(f1.clone());
    functions.add(f2.clone());
    functions.add(f3.clone());

    return functions;
}

TEST(Func_list_Test, Container) {
    auto functions = construct();
    ASSERT_EQ(functions.last_min(1), 2);
}


TEST(Func_list_Test, Size) {
    auto functions = construct();
    EXPECT_EQ(functions.get_size(), 4);
}


TEST(Func_list_Test, constructor) {
    auto function = FunctionList();
    EXPECT_EQ(function.get_size(), 0);
}


TEST(Func_list_Test, insert) {
   auto functions = construct();
   auto f = Power(3, 5);
   functions.insert(2, f.clone());
   EXPECT_EQ(functions.get_size(), 5);
}

TEST(Func_list_Test, Remove) {
    auto  functions = construct();
    functions.remove(1);

    ASSERT_ANY_THROW(functions.remove(5));
    ASSERT_ANY_THROW(functions.remove(-1));
    ASSERT_NO_THROW(functions.remove(2));
    EXPECT_EQ(functions.get_size(), 2);
}

TEST(Func_list_Test, Copy) {
    auto  functions = construct();
    auto functions1(functions);
    EXPECT_EQ(functions.get_size(), 4);
}

TEST(Func_list_Test, Add) {
    FunctionList functions;
    auto f = Power(3, 5);
    functions.add(f.clone());
    EXPECT_EQ(functions.get_size(), 1);
}

TEST(Func_list_Test, Clear)
{
    auto functions = construct();
    functions.clear();
    EXPECT_EQ(functions.get_size(), 0);
}

TEST(Func_list_Test, Swap) {
    auto functions = construct();
    FunctionList functions1;
    auto f = Power(3, 5);
    auto f1 = Log(4);

    functions1.add(f.clone());
    functions1.add(f1.clone());

    functions.swap(functions1);
    EXPECT_EQ(functions.get_size(), 2);
    EXPECT_EQ(functions1.get_size(), 4);

}