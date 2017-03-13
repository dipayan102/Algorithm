//
// Created by Dipayan Bhattacharya on 2/12/17.
//

#ifndef ALGORITHM_UTILS_HPP
#define ALGORITHM_UTILS_HPP

#include <iostream>
#include <vector>

class Utils {
public:
    void swap(int *x, int *y);
    void shuffle(int *arr, int size);
    int *get_random_number_list(int size);
    std::string longestCommonPrefix(std::vector<std::string>& strs);
};

#endif //ALGORITHM_UTILS_HPP
