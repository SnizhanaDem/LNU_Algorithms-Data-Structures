//
// stack.cpp
//
#include "pch.h"
using namespace std;


    void Stack::push(int c) {
        s.push(c);
    }

    void Stack::pop() {
        s.pop();
    }

    int Stack::top() {
        return s.top();
    }

    bool Stack::empty() {
        return s.empty();
    }

    int Stack::size() {
        return s.size();
    }


void printOn(Stack s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
int main(int argc, char** argv) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "Stack: ";
    printOn(s);
    cout << "Top: " << s.top() << "\n";
    while (!s.empty()) {
        s.pop();

        cout << "Stack after pop: ";
        printOn(s);

        if (!s.empty()) {
            cout << "Top after pop: " << s.top() << "\n";
            cout << "Stack is empty (1 - yes | 0 - no): " << s.empty() << "\n";
        }
        else {
            cout << "The stack is empty.\n";
        }

        cout << "Size of stack now: " << s.size() << "\n";
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

