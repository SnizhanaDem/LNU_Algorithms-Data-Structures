//
// mystack.cpp
//
#include "pch.h"
using namespace std;
StackClass::StackClass() {
    sizeArr = 4;
    numberAmount = 0;
    numbers = new int[sizeArr];
}

StackClass::~StackClass() {
    delete[] numbers;
}

void StackClass::push(int plusInteger) {
    if (isFull()) {
        addSpace();
    }
    numbers[numberAmount] = plusInteger;
    numberAmount++;
}

void StackClass::pop() {
    if (!isEmpty()) {
        numberAmount--;
        if (sizeArr > 4 && numberAmount <= (sizeArr / 4)) {
            reduceSpace();
        }
    }
}

void StackClass::printOn() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        for (int i = numberAmount - 1; i >= 0; i--) {
            cout << numbers[i] << " ";
        }
    }
}

int StackClass::size() {
    return numberAmount;
}

int StackClass::top() {
    if (!isEmpty()) {
        return numbers[numberAmount - 1];
    }
    else {
        throw out_of_range("Stack is empty");
    }
}
bool StackClass::isEmpty() {
    return (numberAmount == 0);
}

bool StackClass::isFull() {
    return (numberAmount == sizeArr);
}

void StackClass::addSpace() {
    sizeArr = sizeArr * 2;
    int* increasedNumbersArr = new int[sizeArr];
    for (int i = 0; i < numberAmount; i++) {
        increasedNumbersArr[i] = numbers[i];
    }
    delete[] numbers;
    numbers = increasedNumbersArr;
}

void StackClass::reduceSpace() {
    sizeArr = sizeArr / 2;
    int* reducedNumbersArr = new int[sizeArr];
    for (int i = 0; i < numberAmount; i++) {
        reducedNumbersArr[i] = numbers[i];
    }
    delete[] numbers;
    numbers = reducedNumbersArr;
}
int main(int argc, char** argv) {
    StackClass stack;

    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(7);
    stack.push(1);

    int i = 0;
    int val;
    while (i != 2) {
        val = stack.top();
        stack.pop();
        i++;

    }
    cout << val<<endl;

    //cout << "Stack contents: ";
    //stack.printOn();
    //cout << endl;

    //    while (!stack.isEmpty()) {
    //   
    //    stack.pop();
   
    //    if (!stack.isEmpty()) {
    //        cout << "Stack after popping: ";
    //        stack.printOn();
    //        cout << "\nStack top:" << stack.top() << endl;
    //        cout << "Stack size:" << stack.size() << endl;
    //        cout << "Stack is empty (1-yes | 0 - no): " << stack.isEmpty() << "\n";
    //    }
    //    else {
    //        cout << "Stack after popping: ";
    //        stack.printOn();
    //        cout << "Stack size:" << stack.size() << endl;
    //    }
    //}

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

