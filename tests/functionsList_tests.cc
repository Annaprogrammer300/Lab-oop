#include <gtest/gtest.h>

#include <Function1/Function1.h>
using namespace function;
using namespace std;


TEST(Func_list_Test, Container) {
    FunctionList functions;
    Function one(Type::power, 2, 3),
        two(Type::power, 1, 3),
        three(Type::log, 1),
        four(Type::log, 2);
    functions.add(one);
    functions.add(two);
    functions.add(three);
    functions.add(four);

    int index = functions.last_min(1);

    ASSERT_EQ(index, 2);
}


TEST(Func_list_Test, Size) {
    FunctionList functions;
    Function one(Type::power, 2, 3),
        two(Type::power, 1, 3),
        three(Type::log, 1),
        four(Type::log, 2);
    functions.add(one);
    functions.add(two);
    functions.add(three);
    functions.add(four);

    EXPECT_EQ(functions.get_size(), 4);
}


TEST(Func_list_Test, constructor) {
    FunctionList functions;
    EXPECT_EQ(functions.get_size(), 0);
}


TEST(Func_list_Test, insert) {
    FunctionList functions;
    Function one(Type::power, 2, 3),
        two(Type::power, 1, 3),
        three(Type::log, 1),
        four(Type::log, 2);
    functions.add(one);
    functions.add(two);
    functions.add(three);
    functions.add(four);

    ASSERT_ANY_THROW(functions.insert(5, { Function(Type::power, 5, 2) }));
    ASSERT_NO_THROW(functions.insert(2, { Function(Type::power, 5, 2) }));
}

TEST(Func_list_Test, remove) {
    FunctionList functions;
    Function one(Type::power, 2, 3),
        two(Type::power, 1, 3),
        three(Type::log, 1),
        four(Type::log, 2);
    functions.add(one);
    functions.add(two);
    functions.add(three);
    functions.add(four);

    ASSERT_ANY_THROW(functions.remove(5));
    ASSERT_ANY_THROW(functions.remove(-1));
    ASSERT_NO_THROW(functions.remove(2));
}

TEST(Func_list_Test, test1) {
    FunctionList functions;
    Function one(Type::power, 2, 3),
        two(Type::power, 1, 3),
        three(Type::log, 1),
        four(Type::log, 2);
    functions.add(one);
    functions.add(two);
    functions.add(three);
    functions.add(four);

    functions.remove(3);
    EXPECT_EQ(functions.get_size(), 3);

    functions.insert(2, { Function(Type::power, 5, 2) });
    EXPECT_EQ(functions.get_size(), 4);
}
