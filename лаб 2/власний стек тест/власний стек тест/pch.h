//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>

class StackClass {
private:
    int sizeArr;
    int numberAmount;
    int* numbers;

public:
    StackClass();
    ~StackClass();

    void push(int plusInteger);
    void pop();
    bool isEmpty();
    bool isFull(); 
    int size(); 
    int top();
    void printOn();

private:
    void addSpace();
    void reduceSpace();
};
