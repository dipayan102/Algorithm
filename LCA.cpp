//
// Created by Dipayan Bhattacharya on 2/11/17.
//

#include <iostream>
#include "BinarySearchTree.hpp"

using namespace std;

BstNode * lowestCommonAnscestor(BstNode *root, BstNode *left, BstNode *right) {
    if(root == nullptr) {
        return nullptr;
    } else {
        if(root->data >= left->data && root->data <= right->data) {
            return root;
        } else if(root->data > right->data) {
            return lowestCommonAnscestor(root->left, left, right);
        } else if(root->data < left->data) {
            return lowestCommonAnscestor(root->right, left, right);
        } else {
            return nullptr;
        }
    }
}

int main() {
    BstTest test;
    BinarySearchTree *bst = test.createBST();
    test.dispAllOrders(bst);
    BstNode *left = bst->findNode(bst->bst_root, 1);
    BstNode *right = bst->findNode(bst->bst_root, 2);
    if(left == nullptr || right == nullptr) {
        cout<<"Could not find one of the left or right nodes! Quitting.";
        return -1;
    }
    cout<<"Lowest common anscestor of "<<left->data<<" and "<<right->data<<" = "
    <<lowestCommonAnscestor(bst->bst_root, left, right)->data;
    return 0;
}

