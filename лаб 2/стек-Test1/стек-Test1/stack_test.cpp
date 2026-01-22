#include "pch.h"

TEST(StackTest, PushPopTest) {
    Stack s;
    s.push(1);
    ASSERT_EQ(s.top(), 1);
    s.pop();
    ASSERT_TRUE(s.empty());
}

TEST(StackTest, SizeTest) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    ASSERT_EQ(s.size(), 4);
}

TEST(StackTest, EmptyTest) {
    Stack s;
    ASSERT_TRUE(s.empty());
    s.push('1');
    ASSERT_FALSE(s.empty());
}

TEST(StackTest, TopTest) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    ASSERT_EQ(s.top(), 5);
    s.pop();
    ASSERT_EQ(s.top(), 4);
}

