//
// Created by Dipayan Bhattacharya on 3/12/17.
//
#include "SortUtil.hpp"
#include <iostream>

using namespace std;

void dispArr(int* arr, int len) {
    cout<<"[";
    for(int i=0;i<len;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}


int main() {
    int arr[] = {1,5,9,2,4,2,3,4,7};
    int len = sizeof(arr) / sizeof(int);
    SortUtil s;
    s.mergeSort(arr, len);
    dispArr(arr, len);
    return 0;
}
