//
// pch.h
//
#pragma once
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

const int N = 4, M = 8;

int sizeMatrix(int sparseMatrix[N][M]);
void makeNewMatrix(int sparseMatrix[N][M], int** compactMatrix);
void printSparseMatrix(int sparseMatrix[N][M]);
void printCompactMatrix(int** compactMatrix, int size);
void addElement(int** compactMatrix, int& size, int row, int column, int value);
void removeElement(int** compactMatrix, int& size, int index);
int findElement(int** compactMatrix, int size, int row, int column);

