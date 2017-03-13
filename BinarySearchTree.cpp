//
// Created by Dipayan Bhattacharya on 2/11/17.
//

#include "BinarySearchTree.hpp"
#include <iostream>

using namespace std;

void BinarySearchTree::insertData(BstNode **root, int data) {
    BstNode *node = *root;
    if(node == nullptr) {
        node = new BstNode(data);
        *root = node;
    } else {
        if(data < node->data) {
            insertData(&node->left, data);
        } else if(data > node->data) {
            insertData(&node->right, data);
        }
    }
}

BstNode * BinarySearchTree::findNode(BstNode *root, int data) {
    if(root == nullptr) {
        return nullptr;
    } else {
        if(root->data > data) {
            return findNode(root->left, data);
        } else if(root->data < data) {
            return findNode(root->right, data);
        } else {
            return root;
        }
    }
}

BstNode * BinarySearchTree::findMin(BstNode *root) {
    BstNode *result;
    if(root == nullptr) {
        result = nullptr;
    } else {
        if(root->left == nullptr) {
            result = root;
        } else {
            result = findMin(root->left);
        }
    }
    return result;
}

BstNode * BinarySearchTree::findMax(BstNode *root) {
    BstNode *result;
    if(root == nullptr) {
        result = nullptr;
    } else {
        if(root->right == nullptr) {
            result = root;
        } else {
            result = findMax(root->right);
        }
    }
    return result;
}

void BinarySearchTree::deleteData(BstNode **root, int data) {
    BstNode *node = *root;
    if(node == nullptr) {
        return;
    } else {
        if(data < node->data) {
            deleteData(&node->left, data);
        } else if(data > node->data) {
            deleteData(&node->right, data);
        } else {
            if(node->left == nullptr && node->right == nullptr) {
                delete node;
                *root = nullptr;
            } else if(node->left == nullptr && node->right != nullptr) {
                *root = node->right;
                delete node;
                node = nullptr;
            } else if(node->right == nullptr && node->left != nullptr) {
                *root = node->left;
                delete node;
                node = nullptr;
            } else {
                // Find maximum element from left subtree to replace the deleted node
                BstNode *max = findMax(node->left);
                node->data = max->data;
                deleteData(&node->left, max->data);
            }
        }
    }
}

void BinarySearchTree::dispPreOrder(BstNode *root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data <<" ";
    dispPreOrder(root->left);
    dispPreOrder(root->right);
}

void BinarySearchTree::dispInOrder(BstNode *root) {
    if(root == nullptr) {
        return;
    }
    dispInOrder(root->left);
    cout << root->data <<" ";
    dispInOrder(root->right);
}

void BinarySearchTree::dispPostOrder(BstNode *root) {
    if(root == nullptr) {
        return;
    }
    dispPostOrder(root->left);
    dispPostOrder(root->right);
    cout << root->data <<" ";
}

int BinarySearchTree::getMaxDepth(BstNode *root, int depth) {
    if(root == nullptr) {
        return 0;
    }
    depth = 1 + max(getMaxDepth(root->left, depth+1), getMaxDepth(root->right, depth+1));
    return depth;
}

int BinarySearchTree::getMaxDepth() {
    return getMaxDepth(this->bst_root,1);
}

void BinarySearchTree::dispLevelOrder_recursive(BstNode *root, int level) {
    if(root == nullptr) {
        return;
    } else {
        if(level == 1) {
            cout<<root->data<<" ";
        }
        else if(level > 1) {
            dispLevelOrder_recursive(root->left, level - 1);
            dispLevelOrder_recursive(root->right, level - 1);
        }
    }
}

void BinarySearchTree::dispLevelOrder_non_recursive() {
    deque<BstNode*> q;
    if(bst_root == nullptr) {
        return;
    }
    q.push_back(bst_root);
    while(!q.empty()) {
        BstNode *node = q.front();
        q.pop_front();
        if(node->left) {
            q.push_back(node->left);
        }
        if(node->right) {
            q.push_back(node->right);
        }
        cout<<node->data<<" ";
    }
}

void BinarySearchTree::dispLevelOrder(bool recursive) {
    int maxDepth = getMaxDepth(bst_root, 1);
    if(recursive) {
        for(int i=1;i<=maxDepth;i++) {
            dispLevelOrder_recursive(bst_root, i);
        }
    } else {
        deque<BstNode*> q;
        dispLevelOrder_non_recursive();
    }
}

void BinarySearchTree::dispLevelOrder() {
    dispLevelOrder(true);
}

