//
// pch.h
//
#pragma once
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

class CharSet {
public:
    CharSet(string s = "");
    ~CharSet();

    void add(char a);
    void deletee(char a);
    bool test(char a);
    bool isEmpty()const;

    CharSet association(CharSet& set);
    CharSet intersection(CharSet& set);
    CharSet difference(CharSet& set);

    friend bool operator==(CharSet& t1, CharSet& t2);

    void print();

private:
    unsigned int sets[26] = { 0 };
};
