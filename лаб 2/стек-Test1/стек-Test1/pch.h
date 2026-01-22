//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <stack>


class Stack {
private:
    std::stack<int> s;

public:
    void push(int c);

    void pop();

    int top();

    bool empty();

    int size();
};
