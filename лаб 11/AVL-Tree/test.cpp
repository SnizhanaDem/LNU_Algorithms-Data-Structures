#include "pch.h"

TEST(AVLTreeTest, HeightTest) {
    Node* root = nullptr;
    EXPECT_EQ(height(root), 0);

    root = newNode(10);
    EXPECT_EQ(height(root), 1);
}

TEST(AVLTreeTest, MaxTest) {
    EXPECT_EQ(max(5, 10), 10);
    EXPECT_EQ(max(15, 3), 15);
    EXPECT_EQ(max(7, 7), 7);
}

TEST(AVLTreeTest, NewNodeTest) {
    Node* node = newNode(10);
    EXPECT_EQ(node->key, 10);
    EXPECT_EQ(node->left, nullptr);
    EXPECT_EQ(node->right, nullptr);
    EXPECT_EQ(node->height, 1);
}

TEST(AVLTreeTest, RightRotateTest) {
    Node* y = newNode(30);
    y->left = newNode(20);
    y->left->left = newNode(10);

    y = rightRotate(y);

    ASSERT_EQ(y->key, 20);
    ASSERT_EQ(y->right->key, 30);
    ASSERT_EQ(y->left->key, 10);
}

TEST(AVLTreeTest, LeftRotateTest) {
    Node* x = newNode(10);
    x->right = newNode(20);
    x->right->right = newNode(30);

    x = leftRotate(x);

    ASSERT_EQ(x->key, 20);
    ASSERT_EQ(x->left->key, 10);
    ASSERT_EQ(x->right->key, 30);
}

TEST(AVLTreeTest, BalanceTest) {
    Node* root = nullptr;
    EXPECT_EQ(getBalance(root), 0);

    root = newNode(10);
    EXPECT_EQ(getBalance(root), 0);

    root->left = newNode(5);
    EXPECT_EQ(getBalance(root), 1);

    root->right = newNode(15);
    EXPECT_EQ(getBalance(root), 0);

    root->right->right = newNode(20);
    EXPECT_EQ(getBalance(root), 0);
}

TEST(AVLTreeTest, InsertionAndDeletion) {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    root = deleteNode(root, 20);
    EXPECT_TRUE(search(root, 10));
    EXPECT_TRUE(search(root, 25));
    EXPECT_TRUE(search(root, 30));
    EXPECT_TRUE(search(root, 40));
    EXPECT_TRUE(search(root, 50));
    EXPECT_FALSE(search(root, 20));
    EXPECT_FALSE(search(root, 35));
}
TEST(AVLTreeTest, SearchTest) {
    Node* root = nullptr;
    EXPECT_FALSE(search(root, 10));

    root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);

    EXPECT_TRUE(search(root, 10));
    EXPECT_TRUE(search(root, 5));
    EXPECT_TRUE(search(root, 15));
    EXPECT_TRUE(search(root, 3));
    EXPECT_TRUE(search(root, 7));

    EXPECT_FALSE(search(root, 1));
    EXPECT_FALSE(search(root, 8));
}
