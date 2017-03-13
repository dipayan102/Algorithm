//
// Created by Dipayan Bhattacharya on 2/21/17.
//

#include "utils.hpp"

using namespace std;

Utils u;
void test_lcp() {
    vector<string> strs = {"abc", "abcd", "abcde"};
    string lcp = u.longestCommonPrefix(strs);
    cout<<"LCP = "<<lcp<<endl;
    strs.clear();
    strs = {"aaa", "aa", "aaa"};
    lcp = u.longestCommonPrefix(strs);
    cout<<"LCP = "<<lcp<<endl;
    strs.clear();
    strs = {"aac", "c", "aa"};
    lcp = u.longestCommonPrefix(strs);
    cout<<"LCP = "<<lcp<<endl;
}

int main(int argc, char **argv) {
    test_lcp();
}

