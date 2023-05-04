#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;
using namespace std;


TEST(Func_list_Test, Container) {
    FunctionList functions;
    functions.add(Function(Type::power, 2, 3));
    functions.add(Function(Type::power, 1, 3));
    functions.add(Function(Type::log, 1));
    functions.add(Function(Type::log, 2));

    int index = functions.last_min(1);

    ASSERT_EQ(index, 2);
}


TEST(Func_list_Test, Size) {
    FunctionList functions;
    functions.add(Function(Type::power, 2, 3));
    functions.add(Function(Type::power, 1, 3));
    functions.add(Function(Type::log, 1));
    functions.add(Function(Type::log, 2));

    EXPECT_EQ(functions.get_size(), 4);
}


TEST(Func_list_Test, constructor) {
    FunctionList functions;
    EXPECT_EQ(functions.get_size(), 0);
}


TEST(Func_list_Test, insert) {
    FunctionList functions;
    functions.add(Function(Type::power, 2, 3));
    functions.add(Function(Type::power, 1, 3));
    functions.add(Function(Type::log, 1));
    functions.add(Function(Type::log, 2));

    ASSERT_ANY_THROW(functions.insert(5, { Function(Type::power, 5, 2) }));
    ASSERT_NO_THROW(functions.insert(2, { Function(Type::power, 5, 2) }));
    EXPECT_EQ(functions.get_size(), 5);
}

TEST(Func_list_Test, remove) {
    FunctionList functions;
    functions.add(Function(Type::power, 2, 3));
    functions.add(Function(Type::power, 1, 3));
    functions.add(Function(Type::log, 1));
    functions.add(Function(Type::log, 2));

    ASSERT_ANY_THROW(functions.remove(5));
    ASSERT_ANY_THROW(functions.remove(-1));
    ASSERT_NO_THROW(functions.remove(2));
    EXPECT_EQ(functions.get_size(), 3);
}