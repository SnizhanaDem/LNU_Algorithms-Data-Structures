// pch.cpp
#include "pch.h"

size_t height(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* nodeWithMinValue(Node* node)
{
    Node* current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node* temp = nodeWithMinValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void printTree(Node* root, string prefix, bool isLeft) {
    if (root == nullptr) return;

    if (root->right)
        printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);

    cout << prefix << (isLeft ? "\\-- " : "/-- ") << root->key << endl;

    if (root->left)
        printTree(root->left, prefix + (isLeft ? "    " : "|   "), true);
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(int argc, char** argv) {
        Node* root = nullptr;
    
        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 30);
        root = insert(root, 40);
        root = insert(root, 50);
        root = insert(root, 25);
    
 /*       root = insert(root, 1);
        root = insert(root, 2);
        root = insert(root, 3);
        root = insert(root, 4);
        root = insert(root, 5);
        root = insert(root, 6);
        root = insert(root, 7);
        root = insert(root, 8);
        root = insert(root, 9);
        root = insert(root, 10);
        root = insert(root, 11);
        root = insert(root, 12);
        root = insert(root, 13);
        root = insert(root, 14);
        root = insert(root, 15);
        root = insert(root, 16);
        root = insert(root, 17);*/
    
        cout << " AVL tree is: \n";
        printTree(root);
    
        cout << "Preorder traversal of the constructed AVL tree is \n";
        preOrder(root);
    
        cout << "\n\nDeleting  20\n";
        root = deleteNode(root, 20);
    
        cout << "AVL tree after deletion of 20 is \n";
        printTree(root);
    
        cout << "Preorder traversal of the AVL tree after deletion of 20 \n";
        preOrder(root);
    
        cout << "\n\nSearch 30\n";
     
        if (search(root, 30))
            cout << "Key 30 exists in AVL tree\n";
        else
            cout << "Key 30 does not exist in AVL tree\n";
        
        cout << "Search 3100\n";
        
        if (search(root, 3100))
            cout << "Key 3100 exists in AVL tree\n";
        else
            cout << "Key 3100 does not exist in AVL tree\n";
    
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
