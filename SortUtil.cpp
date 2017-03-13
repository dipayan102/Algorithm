//
// Created by Dipayan Bhattacharya on 3/12/17.
//

#include "SortUtil.hpp"

void merge(int *a, int left, int mid, int right) {
    int b[right-left+1];
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right) {
        if(a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while(i <= mid) {
        b[k++] = a[i++];
    }
    while(j <= right) {
        b[k++] = a[j++];
    }
    for(int l=0;l<k;l++) {
        a[left++] = b[l];
    }
}

void recursive_mergeSort(int *arr, int left, int right) {
    int mid = (left + right)/2;
    if(left < right) {
        recursive_mergeSort(arr, left, mid);
        recursive_mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void SortUtil::mergeSort(int *arr, int len) {
    recursive_mergeSort(arr, 0, len-1);
}