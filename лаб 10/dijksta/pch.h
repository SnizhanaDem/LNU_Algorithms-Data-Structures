//
// pch.h
//

#pragma once
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    size_t numberOfVertexes;
    int** matrix;

public:

    Graph(int number);

    void addEdge(int u, int v, int w);
    void removeEdge(int u, int v);
    void print();
    size_t getNumberOfVertexes();
    bool areConnected(size_t i, size_t j);
    int*& operator[](size_t i);
};

class Dijkstra {
private:
    Graph graph;
    bool* marked;
    int* fromAr;
    int* pathLength;

    void init();
    void recalculateLengthFromMarked();
    void markShortest();
    void fillWay(size_t from, size_t to, vector<int>& way);
public:
    Dijkstra(Graph ggraph);
    int findWay(size_t from, size_t to, vector<int>& way);
};
