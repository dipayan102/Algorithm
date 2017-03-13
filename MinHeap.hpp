//
// Created by Dipayan Bhattacharya on 2/11/17.
//

#ifndef ALGORITHM_MINHEAP_HPP
#define ALGORITHM_MINHEAP_HPP

#include <ostream>

#define PARENT(i) ((i-1)/2)
#define LEFT_CHILD(i) (2*i + 1)
#define RIGHT_CHILD(i) (2*i + 2)

class MinHeap {
private:
    int size;
    int max_size;
    int *arr;
    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

public:
    MinHeap(int max_size) {
        this->max_size = max_size;
        arr = new int[max_size];
        size = 0;
    }
    ~MinHeap() {
        delete[] arr;
        arr = nullptr;
    }
    void insert(int data);
    int extract_min();
    int del(int index);
    void minHeapify(int i);
    friend std::ostream& operator<<(std::ostream &os, const MinHeap &minHeap);

};


#endif //ALGORITHM_MINHEAP_HPP
