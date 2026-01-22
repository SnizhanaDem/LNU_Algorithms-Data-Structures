// pch.h
#pragma once

#include <iostream>
#include "gtest/gtest.h"
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

size_t height(Node* n);
int max(int a, int b);
Node* newNode(int key);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
int getBalance(Node* N);
Node* insert(Node* node, int key);
Node* nodeWithMinValue(Node* node);
Node* deleteNode(Node* root, int key);
bool search(Node* root, int key);
void printTree(Node* root, string prefix = "", bool isLeft = true);
void preOrder(Node* root);
