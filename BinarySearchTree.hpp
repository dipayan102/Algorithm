//
// Created by Dipayan Bhattacharya on 2/11/17.
//

#ifndef ALGORITHM_BINARYSEARCHTREE_HPP
#define ALGORITHM_BINARYSEARCHTREE_HPP

#include <iostream>
#include <deque>

class BstNode {
public:
    int data;
    BstNode *left, *right;
    BstNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    void dispLevelOrder_recursive(BstNode *root, int level);
    void dispLevelOrder_non_recursive();
    int getMaxDepth(BstNode *root, int depth);

public:
    BstNode *bst_root;
    BinarySearchTree() {
        bst_root = nullptr;
    }
    void insertData(BstNode **root, int data);
    BstNode * findNode(BstNode *root, int data);
    BstNode * findMin(BstNode *root);
    BstNode * findMax(BstNode *root);
    void deleteData(BstNode **root, int data);
    void dispPreOrder(BstNode *root);
    void dispInOrder(BstNode *root);
    void dispPostOrder(BstNode *root);
    int getMaxDepth();
    void dispLevelOrder();
    void dispLevelOrder(bool recursive);
};

#endif //ALGORITHM_BINARYSEARCHTREE_HPP
