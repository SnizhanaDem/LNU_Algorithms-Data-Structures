#include "pch.h"

int sizeMatrix(int sparseMatrix[N][M])
{
    int size = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (sparseMatrix[i][j] != 0)
                size++;
    return size;
}

void makeNewMatrix(int sparseMatrix[N][M], int** compactMatrix)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (sparseMatrix[i][j] != 0)
            {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
}

void printSparseMatrix(int sparseMatrix[N][M])
{
    cout << "Sparse Matrix:\n";
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printCompactMatrix(int** compactMatrix, int size)
{
    cout << "\nCompact Matrix: \nRow: ";
    for (int i = 0; i < size; i++)
        cout << compactMatrix[0][i] << " ";

    cout << "\nCol: ";
    for (int i = 0; i < size; i++)
        cout << compactMatrix[1][i] << " ";

    cout << "\nVal: ";
    for (int i = 0; i < size; i++)
        cout << compactMatrix[2][i] << " ";
    cout << endl;
}

void addElement(int** compactMatrix, int& size, int row, int column, int value) {
    compactMatrix[0][size] = row;
    compactMatrix[1][size] = column;
    compactMatrix[2][size] = value;
    size++;
    cout << "\nAdded element: Row: " << row << " Col: " << column << " Val: " << value << endl;
}

void removeElement(int** compactMatrix, int& size, int index) {
    cout << "\nRemoved element: Row: " << compactMatrix[0][index] << " Col: " << compactMatrix[1][index] << " Val: " << compactMatrix[2][index] << endl;
    for (int i = index; i < size - 1; i++) {
        compactMatrix[0][i] = compactMatrix[0][i + 1];
        compactMatrix[1][i] = compactMatrix[1][i + 1];
        compactMatrix[2][i] = compactMatrix[2][i + 1];

    }
    size--;
}

//int findElement(int** compactMatrix, int size, int row, int column) {
//    for (int i = 0; i < size; i++) {
//        if (compactMatrix[0][i] == row && compactMatrix[1][i] == column)
//            return compactMatrix[2][i];
//    }
//    return 0;
//}
int findElement(int** compactMatrix, int size, int row, int column) {
    for (int i = 0; i < size; ++i) {
        if (compactMatrix[0][i] == row && compactMatrix[1][i] == column) {
            if (compactMatrix[2][i] != 0) {
                return compactMatrix[2][i];
            }
            else {
                cout << "\nElement at row " << row << ", column " << column << " is deleted\n";
                return -1; 
            }
        }
    }
    cout << "\nElement not found at row " << row << ", column " << column << endl;
    return 0; 
}
void changeElement(int** compactMatrix, int size, int row, int column, int newValue) {
    for (int i = 0; i < size; ++i) {
        if (compactMatrix[0][i] == row && compactMatrix[1][i] == column) {
            compactMatrix[2][i] = newValue;
            cout << "\nChanged element at row " << row << ", column " << column << ": new value = " << newValue << endl;
            return;
        }
    }
    cout << "\nElement not found at row " << row << ", column " << column << endl;
}


int main(int argc, char** argv)
{

    int sparseMatrix[N][M] =
    {
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
    printSparseMatrix(sparseMatrix);
    printCompactMatrix(compactMatrix, size);

    addElement(compactMatrix, size, 3, 2, 7);
    printCompactMatrix(compactMatrix, size);

    int element = findElement(compactMatrix, size, 1, 2);
    cout << "\nFound element at position (1, 2): " << element << endl;

    removeElement(compactMatrix, size, 0);
    int elements = findElement(compactMatrix, size, 0, 2);
    printCompactMatrix(compactMatrix, size);

    changeElement(compactMatrix, size, 1, 2, 8);
    printCompactMatrix(compactMatrix, size);
    delete[] compactMatrix;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}