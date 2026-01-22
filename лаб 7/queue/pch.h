//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <stdexcept>

using namespace std;


class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int newData) : data(newData), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;
    int size;

public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    int getSize() const;
    void push(int newData);
    void pop();
    int front() const;
    int& back();
    void print() const;
};
