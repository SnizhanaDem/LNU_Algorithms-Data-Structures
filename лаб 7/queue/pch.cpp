//
// pch.cpp
//

#include "pch.h"

Queue::Queue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}

Queue::~Queue() {
    while (!isEmpty()) {
        pop();
    }
}

bool Queue::isEmpty() const {
    return size == 0;
}

int Queue::getSize() const {
    return size;
}

void Queue::push(int newData) {
    Node* newNode = new Node(newData);
    if (isEmpty()) {
        frontPtr = newNode;
        rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    size++;
}

void Queue::pop() {
    if (!isEmpty()) {
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        size--;
        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }
    }
    else {
        cerr << "Error: Queue is empty. Cannot pop.\n";
    }
}

int Queue::front() const {
    if (!isEmpty()) {
        return frontPtr->data;
    }
    else {
        throw out_of_range("Error: Queue is empty. No front element.");
    }
}

int& Queue::back() {
    if (isEmpty()) {
        throw out_of_range("Error: Queue is empty. No back element.");
    }
    return rearPtr->data;
}

void Queue::print() const {
    
    Node* current = frontPtr;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(int argc, char** argv) {
    Queue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    cout << "Queue: ";
    myQueue.print();
    if (myQueue.isEmpty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        cout << "The queue is not empty" << endl;
    }
    cout << "Back element: " << myQueue.back() << endl;
    cout << "Front element:" << myQueue.front() << endl;
    cout << "Size:" << myQueue.getSize() << endl;
    

    myQueue.pop();
    cout << "Queue after pop:";
    myQueue.print();
    if (myQueue.isEmpty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        cout << "The queue is not empty" << endl;
    }

    cout << "Back element: " << myQueue.back() << endl;
    cout << "Front element:" << myQueue.front() << endl;
    cout << "Size:" << myQueue.getSize() << endl;
 
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

