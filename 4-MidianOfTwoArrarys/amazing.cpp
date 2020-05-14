#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        double res1,res2;
        nums1.push_back(2147483647);
        nums2.push_back(2147483647);
        int i = 0, j = 0;
        while (i + j <= (len1 + len2) / 2)
        {
            res1 = res2;
            if(nums1[i] >= nums2[j]) res2 = nums2[j++];
            else res2 = nums1[i++];
        }
        if ((len1 + len2) % 2 == 0)
            return (res1 + res2) / 2.0;
        return res2;
    }
};