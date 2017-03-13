//
// Created by Dipayan Bhattacharya on 2/13/17.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 1) Calculate the medians m1 and m2 of the input arrays ar1[]
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
 */

double findMedian(int *nums, int len) {
    if(len % 2 == 0) {
        return ((double)(nums[len/2 - 1] + nums[len/2]))/2;
    } else {
        return nums[len/2];
    }
}

double findMedianOfTwoArrays(int * nums1, int len1, int * nums2, int len2) {
    double m1 = findMedian(nums1, len1);
    double m2 = findMedian(nums2, len2);
    if(m1 == m2) {
        return m1;
    } else if(len1 == 2 && len2 == 2) {
        return (max(nums1[0], nums2[0]), min(nums1[1], nums2[1]))/2;
    } else if(m1 > m2) {
        return findMedianOfTwoArrays(nums1, len1/2, nums2+len2/2, len2/2);
    } else if(m2 > m1) {
        return findMedianOfTwoArrays(nums1+len1/2, len1/2, nums2, len2/2);
    }
    return -1;
}
int main() {
    int nums1[] = {1,2,3,4,5};
    int nums2[] = {6,7,8,9,10};
    cout<<"Median = "<<findMedianOfTwoArrays(nums1, 5, nums2, 5)<<endl;
}