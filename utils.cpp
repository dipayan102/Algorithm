//
// Created by Dipayan Bhattacharya on 2/12/17.
//
#include "utils.hpp"
#include <sstream>

using namespace std;

void Utils::swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void Utils::shuffle(int *arr, int size) {
    srand((unsigned)time(0));
    for(int i=0;i<size-1;i++) {
        int b = i + (rand()%(size-i-1) + 1);
        swap(&arr[i], &arr[b]);
    }
}

int * Utils::get_random_number_list(int size) {
    int *arr = new int[size];
    for(int i=0;i<size;i++) {
        arr[i] = i;
    }
    shuffle(arr, size);
    return arr;
}

string Utils::longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) {
        return "";
    } else if(strs.size() == 1) {
        return strs[0];
    }
    stringstream result;
    result<<"";
    for(int i=0;strs[0].length()>0 && i < strs[0].length();i++) {
        for(int j=1;j<strs.size();j++) {
            if(i >= strs[j-1].size()) {
                return result.str();
            }
            char c1 = strs[j-1][i];
            char c2 = strs[j][i];
            if(c1 != c2) {
                return result.str();
            }
        }
        result<<strs[0][i];
    }
    return result.str();
}
