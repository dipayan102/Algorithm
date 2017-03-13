//
// Created by Dipayan Bhattacharya on 2/16/17.
//

#ifndef ALGORITHM_TRIE_HPP
#define ALGORITHM_TRIE_HPP

#include <iostream>
#include <vector>

#define ALPHABET_SIZE 26

class TrieNode {
private:
    bool isLeaf;

public:
    TrieNode *children[ALPHABET_SIZE];
    TrieNode() {
        memset(children, 0, ALPHABET_SIZE*sizeof(TrieNode*));
        isLeaf = false;
    }

    bool isLeafNode() const {
        return isLeaf;
    }

    void setIsLeaf(bool isLeaf) {
        this->isLeaf = isLeaf;
    }

    void setChildAtIndex(TrieNode *child, char letter) {
        int idx = (int)letter - 97;
        if(idx >= 0 && idx < ALPHABET_SIZE) {
            children[idx] = child;
        }
    }

    TrieNode * getChildAtIndex(char letter) {
        int idx = (int)letter - 97;
        if(idx >= 0 && idx < ALPHABET_SIZE) {
            return children[idx];
        } else {
            return nullptr;
        }
    }

    TrieNode *const *getChildren() const {
        return children;
    }

    ~TrieNode() {
        for(TrieNode * node : children) {
            if(node != nullptr) {
                delete node;
            }
        }
    }
};

class Trie {
private:
    TrieNode *root;
    long mem_size;

    // Internal Functions
    void recursive_insert(const char *word, TrieNode *curNode, int idx);
    TrieNode * recursive_search(const char *word, TrieNode *curNode, int idx);
    void recursive_get_words(std::vector<std::string>& result,
                             std::string curWord,
                             TrieNode *curNode);

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        mem_size  = sizeof(root);
    }

    /** Inserts a word into the trie. */
    void insert(std::string word);

    /** Returns if the word is in the trie. */
    bool search(std::string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix);

    std::vector<std::string> getAllWordsInTrie();


    long get_mem_size() const {
        return mem_size;
    }

    ~Trie() {
        delete root;
    }
};

#endif //ALGORITHM_TRIE_HPP
