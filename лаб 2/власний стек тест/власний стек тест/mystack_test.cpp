#include "pch.h"
TEST(StackTest, PushPopTest) {
    StackClass s;
    s.push(1);
    ASSERT_EQ(s.top(), 1);
    s.pop();
    ASSERT_TRUE(s.isEmpty());
}

TEST(StackTest, SizeTest) {
    StackClass s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    ASSERT_EQ(s.size(), 5);
}

TEST(StackTest, EmptyTest) {
    StackClass s;
    ASSERT_TRUE(s.isEmpty());
    s.push('1');
    ASSERT_FALSE(s.isEmpty());
}

TEST(StackTest, TopTest) {
    StackClass s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    ASSERT_EQ(s.top(), 5);
    s.pop();
    ASSERT_EQ(s.top(), 4);
}
TEST(StackTest, IsFull) {
    StackClass stack;
    EXPECT_FALSE(stack.isFull());
    for (int i = 0; i < 4; ++i) {
        stack.push(i);
    }
    EXPECT_TRUE(stack.isFull());
}
