//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pair {
    string key;
    int value;
};

class Table {
public:
    Table();
    void insert(const string& key, int value);
    void replace(const string& key, int newValue);
    void erase(const string& key);
    int find(const string& key) const;
    void print() const;
    size_t tableSize() const;
    void clearTable();
    bool isEmpty() const;

private:
    vector<Pair> pairs;
};
