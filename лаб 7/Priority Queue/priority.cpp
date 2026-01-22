//
// priority.cpp
//

#include "pch.h"
PriorityQueue::PriorityQueue() : head(nullptr), rear(nullptr) {}

void PriorityQueue::push(int data, int prio) {
    Node* newNode = new Node(data, prio);
    if (head == nullptr || prio < head->priority) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority <= prio) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }
    if (rear == nullptr) {
        rear = newNode;
    }
}
void PriorityQueue::pop() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    else {
        cerr << "Error: Queue is empty. Cannot pop.\n";
    }
}

bool PriorityQueue::isEmpty() const {
	return head == nullptr;
}

int PriorityQueue:: getSize() const {
    int size = 0;
    Node* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}
 
int PriorityQueue::front() const {
    if (!isEmpty()) {
        return head->data;
    }
    else {
        throw out_of_range("Error: Queue is empty. No front element.");
    }
}

int& PriorityQueue::back() {
    if (isEmpty()) {
        throw out_of_range("Error: Queue is empty. No back element.");
    }
    return rear->data;
}

void PriorityQueue::print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
PriorityQueue::~PriorityQueue() {
    while (!isEmpty()) {
        pop();
    }
}
int main(int argc, char** argv) {
    queue<int> stl;
    stl.push(3);
    stl.push(5);
    stl.push(7);
    stl.push(1);
    stl.push(2);
    cout << "Queue elements without priority: ";
    while (!stl.empty()) {
        cout << stl.front() << " ";
        stl.pop();
    }
    cout << endl;

    PriorityQueue myQueue;
    myQueue.push(3,3);
    myQueue.push(5,1);
    myQueue.push(7,2);
    myQueue.push(1,1);
    myQueue.push(2,4);
    cout << "Priority Queue: ";
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
    cout << "Priority Queue after pop:";
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