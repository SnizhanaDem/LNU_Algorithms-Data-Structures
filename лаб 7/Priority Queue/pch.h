//
// pch.h
//

#pragma once
#include <iostream>
#include <queue>
#include "gtest/gtest.h"
using namespace std;

struct Node {
	int data;
	int priority;
	Node* next;

	Node(int data, int priority) : data(data), priority(priority), next(nullptr) {}
};
class PriorityQueue {
	Node* head;
	Node* rear;
public:
	PriorityQueue();
	~PriorityQueue();
	bool isEmpty() const;
	int getSize() const;
	void push(int newData, int prio);
	void pop();
	int front() const;
	int& back();
	void print() const;

};