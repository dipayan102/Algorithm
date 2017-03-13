//
// Created by Dipayan Bhattacharya on 2/16/17.
//

#include "trie.hpp"
#include <iostream>

void Trie::recursive_insert(const char *word, TrieNode *curNode, int idx) {
    TrieNode *nextNode = curNode->getChildAtIndex(word[idx]);
    if(nextNode == nullptr) {
        nextNode = new TrieNode();
        mem_size += sizeof(nextNode);
        curNode->setChildAtIndex(nextNode, word[idx]);
    }
    if(word[idx + 1] != 0) {
        recursive_insert(word, nextNode, idx + 1);
    } else {
        curNode->setIsLeaf(true);
    }
}

TrieNode * Trie::recursive_search(const char *word, TrieNode *curNode, int idx) {
    TrieNode *nextNode = curNode->getChildAtIndex(word[idx]);
    if(nextNode == nullptr) {
        return nullptr;
    }
    if(word[idx + 1] != 0) {
        return recursive_search(word, nextNode, idx + 1);
    } else {
        return curNode;
    }
}

void Trie::recursive_get_words(std::vector<std::string>& result,
                            std::string curWord, TrieNode *curNode) {
    if(curNode == nullptr) {
        return;
    }

    for(int i=0; i<ALPHABET_SIZE; i++) {
        if(curNode->children[i] != nullptr) {
            if(curNode->isLeafNode()) {
                result.push_back(curWord + (char)(i + 97));
            }
            recursive_get_words(result, curWord + (char)(i + 97), curNode->children[i]);
        }
    }
}

std::vector<std::string> Trie::getAllWordsInTrie() {
    std::vector<std::string> result;
    recursive_get_words(result, "", root);
    return result;
}

void Trie::insert(std::string word) {
    const char *cword = word.c_str();
    recursive_insert(cword, this->root, 0);
}

bool Trie::startsWith(std::string word) {
    const char *cword = word.c_str();
    return recursive_search(cword, this->root, 0) != nullptr;
}

bool Trie::search(std::string word) {
    const char *cword = word.c_str();
    TrieNode * lastNode = recursive_search(cword, this->root, 0);
    return lastNode != nullptr && lastNode->isLeafNode();
}
