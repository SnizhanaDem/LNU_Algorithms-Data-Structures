#include "pch.h"


TEST(SparseMatrixTest, SizeMatrixTest) {
    int sparseMatrix[N][M] = {
        {0, 0, 3, 0, 4, 0, 2, 0},
        {0, 0, 5, 7, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 2, 6, 0, 0, 0, 0, 0}
    };

    int size = sizeMatrix(sparseMatrix);
    EXPECT_EQ(size, 10);
}

TEST(AddElementTest, AddsElementCorrectly) {
    int size = 0;
    int** compactMatrix = new int* [3];
    for (int i = 0; i < 3; i++)
        compactMatrix[i] = new int[10]; 
    addElement(compactMatrix, size, 2, 3, 8);
    EXPECT_EQ(size, 1);
    EXPECT_EQ(compactMatrix[0][0], 2);
    EXPECT_EQ(compactMatrix[1][0], 3);
    EXPECT_EQ(compactMatrix[2][0], 8);
    delete[] compactMatrix;
}
TEST(RemoveElementTest, RemovesElementCorrectly) {
    int size = 3;
    int** compactMatrix = new int* [3];
    for (int i = 0; i < 3; i++)
        compactMatrix[i] = new int[3];
    compactMatrix[0][0] = 1;
    compactMatrix[1][0] = 2;
    compactMatrix[2][0] = 5;
    compactMatrix[0][1] = 3;
    compactMatrix[1][1] = 4;
    compactMatrix[2][1] = 7;
    compactMatrix[0][2] = 5;
    compactMatrix[1][2] = 6;
    compactMatrix[2][2] = 9;
    removeElement(compactMatrix, size, 1);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(compactMatrix[0][0], 1);
    EXPECT_EQ(compactMatrix[1][0], 2);
    EXPECT_EQ(compactMatrix[2][0], 5);
    EXPECT_EQ(compactMatrix[0][1], 5);
    EXPECT_EQ(compactMatrix[1][1], 6);
    EXPECT_EQ(compactMatrix[2][1], 9);
    delete[] compactMatrix;
}

TEST(FindElementTest, FindsElementCorrectly) {
    int size = 3;
    int** compactMatrix = new int* [3];
    for (int i = 0; i < 3; i++)
        compactMatrix[i] = new int[3];
    compactMatrix[0][0] = 1;
    compactMatrix[1][0] = 2;
    compactMatrix[2][0] = 5;
    compactMatrix[0][1] = 3;
    compactMatrix[1][1] = 4;
    compactMatrix[2][1] = 7;
    compactMatrix[0][2] = 5;
    compactMatrix[1][2] = 6;
    compactMatrix[2][2] = 9;
    EXPECT_EQ(findElement(compactMatrix, size, 3, 4), 7);
    delete[] compactMatrix;
}

TEST(MakeNewMatrixTest, ConvertsSparseToCompactMatrix) {
    int sparseMatrix[N][M] = {
        {0, 0, 3, 0, 4, 0, 2, 0},
        {0, 0, 5, 7, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 2, 6, 0, 0, 0, 0, 0}
    };
    int size = sizeMatrix(sparseMatrix);
    int** compactMatrix = new int* [3];
    for (int i = 0; i < 3; i++)
        compactMatrix[i] = new int[size];
    makeNewMatrix(sparseMatrix, compactMatrix);
    EXPECT_EQ(compactMatrix[0][0], 0);
    EXPECT_EQ(compactMatrix[1][0], 2);
    EXPECT_EQ(compactMatrix[2][0], 3);
    EXPECT_EQ(compactMatrix[0][1], 0);
    EXPECT_EQ(compactMatrix[1][1], 4);
    EXPECT_EQ(compactMatrix[2][1], 4);
    delete[] compactMatrix;
}



