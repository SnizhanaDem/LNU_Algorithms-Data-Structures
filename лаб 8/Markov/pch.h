//
// pch.h
//

#pragma once

//#include "gtest/gtest.h"
#include <string>

using namespace std;

struct Markov {
    string* rulesIn = nullptr;
    string* rulesOut = nullptr;
    size_t rulesCount = 0;

    Markov(string* rIn = nullptr, string* rOut = nullptr, size_t rC = 0);
    ~Markov();

    string process(string s);
};


