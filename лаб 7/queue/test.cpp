#include "pch.h"

TEST(QueueTest, PushTest) {
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.getSize(), 3);
    EXPECT_EQ(queue.front(), 1);
    EXPECT_EQ(queue.back(), 3);
}

TEST(QueueTest, PopTest) {
    Queue queue;
    queue.push(1);
    queue.push(2);
  
    queue.pop();
    EXPECT_EQ(queue.getSize(), 1);
    EXPECT_EQ(queue.front(), 2);

    queue.pop();
    EXPECT_EQ(queue.getSize(), 0);
    EXPECT_THROW(queue.front(), out_of_range); 
}

TEST(QueueTest, FrontTest) {
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.front(), 1);
}

TEST(QueueTest, BackTest) {
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.back(), 3);
}

TEST(QueueTest, SizeTest) {
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.getSize(), 3);
}

TEST(QueueTest, EmptyTest) {
    Queue emptyQueue;
    Queue nonEmptyQueue;
    nonEmptyQueue.push(1);

    EXPECT_TRUE(emptyQueue.isEmpty());
    EXPECT_FALSE(nonEmptyQueue.isEmpty());
}


