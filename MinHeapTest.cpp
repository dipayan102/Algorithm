//
// Created by Dipayan Bhattacharya on 2/12/17.
//
#include "MinHeap.hpp"
#include <iostream>
#include "utils.hpp"

#define MAX_SIZE 10

using namespace std;

int main(int argc, char **argv) {
    Utils u;
    int *shuffled_list = u.get_random_number_list(MAX_SIZE);
    MinHeap minHeap(MAX_SIZE);
    for(int i=0;i<MAX_SIZE;i++) {
        minHeap.insert(shuffled_list[i]);
        cout<<"Inserted "<<shuffled_list[i]<<endl;
    }
    cout<<"Created the following MinHeap :"<<minHeap<<endl;
    cout<<"Extracting all elements.."<<endl;

    for(int i=0;i<MAX_SIZE;i++) {
        cout<<"Extracted = "<<minHeap.extract_min()<<endl;
        cout<<"MinHeap now : "<<minHeap<<endl<<endl;
    }

    return 0;
}
