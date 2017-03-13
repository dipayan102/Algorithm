//
// Created by Dipayan Bhattacharya on 2/11/17.
//

#include "MinHeap.hpp"
#include <iostream>


void MinHeap::insert(int data) {
    if(size >= max_size) {
        return;
    }
    size++;
    int n = size - 1;
    arr[n] = data;
    while(n >= 0 && arr[PARENT(n)] > arr[n]) {
        swap(&arr[PARENT(n)], &arr[n]);
        n = PARENT(n);
    }
}

int MinHeap::extract_min() {
    if(size <= 0) {
        return -1;
    } else {
        return del(0);
    }
}

int MinHeap::del(int index) {
    if(size <= 0 || index >= size) {
        return -1;
    }
    int retVal = arr[index];
    swap(&arr[size-1], &arr[index]);
    size--;
    minHeapify(index);
    return retVal;
}

void MinHeap::minHeapify(int i) {
    if(i < 0 || i >= size) {
        return;
    }
    int smallest_index = i;
    if(LEFT_CHILD(i) < size && arr[LEFT_CHILD(i)] < arr[smallest_index]) {
        smallest_index = LEFT_CHILD(i);
    }
    if(RIGHT_CHILD(i) < size && arr[RIGHT_CHILD(i)] < arr[smallest_index]) {
        smallest_index = RIGHT_CHILD(i);
    }
    if(smallest_index != i) {
        swap(&arr[i], &arr[smallest_index]);
        minHeapify(smallest_index);
    }
}
std::ostream& operator<<(std::ostream &os, const MinHeap &minHeap) {
    os<<"[ ";
    for(int i=0;i<minHeap.size;i++) {
        os<<minHeap.arr[i]<<" ";
    }
    os<<"]";
    return os;
}
