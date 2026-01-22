#include "pch.h"

TEST(PriorityQueueTest, Push) {
    PriorityQueue pq;
    pq.push(5, 1);
    pq.push(10, 2);
    pq.push(3, 3);
    EXPECT_EQ(pq.getSize(), 3);
}

TEST(PriorityQueueTest, Pop) {
    PriorityQueue pq;
    pq.push(5, 1);
    pq.push(10, 2);
    pq.push(3, 3);
    pq.pop();
    EXPECT_EQ(pq.getSize(), 2);
}

TEST(PriorityQueueTest, IsEmptyQueue) {
    PriorityQueue pq;
    EXPECT_EQ(pq.isEmpty(), true);
    pq.push(5, 1);
    EXPECT_EQ(pq.isEmpty(), false);
}

TEST(PriorityQueueTest, GetSizeQueue) {
    PriorityQueue pq;
    EXPECT_EQ(pq.getSize(), 0);
    pq.push(5, 1);
    pq.push(10, 2);
    EXPECT_EQ(pq.getSize(), 2);
}

TEST(PriorityQueueTest, Front) {
    PriorityQueue pq;
    pq.push(5, 6);
    pq.push(10, 2);
    pq.push(3, 3);
    EXPECT_EQ(pq.front(), 10);
}

TEST(PriorityQueueTest, Back) {
    PriorityQueue pq;
    pq.push(5, 1);
    pq.push(10, 2);
    pq.push(3, 3);
    pq.back() = 15;
    EXPECT_EQ(pq.front(), 15);
}