//
// Created by Dipayan Bhattacharya on 2/11/17.
//

#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"
using namespace std;

BinarySearchTree * createBST() {
    BinarySearchTree *tree = new BinarySearchTree();
    tree->insertData(&tree->bst_root, 5);
    tree->insertData(&tree->bst_root, 3);
    tree->insertData(&tree->bst_root, 4);
    tree->insertData(&tree->bst_root, 1);
    tree->insertData(&tree->bst_root, 2);
    tree->insertData(&tree->bst_root, 7);
    tree->insertData(&tree->bst_root, 6);
    tree->insertData(&tree->bst_root, 9);
    tree->insertData(&tree->bst_root, 8);
    tree->insertData(&tree->bst_root, 10);
    return tree;
}

void dispAllOrders(BinarySearchTree *tree) {
    tree->dispPreOrder(tree->bst_root);
    cout<<endl;
    tree->dispInOrder(tree->bst_root);
    cout<<endl;
    tree->dispPostOrder(tree->bst_root);
    cout<<endl;
    tree->dispLevelOrder(false);
    cout<<"\n\n";
}

void rec_maxSumPath(BstNode *node, int sum, int& max_sum,
                    vector<BstNode *>& cur_path, vector<BstNode *>& result) {
    if(node == nullptr) {
        if(max_sum < sum) {
            max_sum = sum;
            result = cur_path;
        }
        return;
    }
    cur_path.push_back(node);
    rec_maxSumPath(node->left, sum + node->data, max_sum, cur_path, result);
    rec_maxSumPath(node->right, sum + node->data, max_sum, cur_path, result);
    cur_path.pop_back();
}

void maxSumPath(BinarySearchTree *tree) {
    vector<BstNode *> result, cur_path;
    int max_sum = 0;
    rec_maxSumPath(tree->bst_root, 0, max_sum, cur_path, result);
    cout<<"Max sum path in the BST :-";
    for(BstNode * node : result) {
        cout<<node->data<<" ";
    }
    cout<<endl;
}

int main(int argc, char **argv) {
    BinarySearchTree *tree = createBST();
    dispAllOrders(tree);
    cout<<endl;
    maxSumPath(tree);
    tree->deleteData(&tree->bst_root, 5);
    dispAllOrders(tree);
    return 0;
}