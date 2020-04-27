#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getNum(vector<int>& num1, vector<int>& num2, int& count) {
        num1[count] = num2[0];
        num2.insert(num2.end(),0x11111111);
        num2.erase(num2.begin());
        count++;
    };

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int amount = nums1.size() + nums2.size();
        vector<int> nums3(amount);
        int count = 0;
        while(count < amount) {
            if(!(nums1.empty() || nums2.empty())) {
                if(nums1[0] <= nums2[0])
                    getNum(nums3,nums1,count);
                else
                    getNum(nums3,nums2,count);
            }
            else
            {
                if(nums1.empty()) 
                    getNum(nums3,nums2,count);
                else
                    getNum(nums3,nums1,count);
            }  
        }

        if(amount % 2 == 0) {
            return double(nums3[amount/2 - 1] + nums3[amount/2]) / 2;
        }
        else
        {
            return double(nums3[amount/2]);
        }
    }
};

int main(){
    vector<int> nums1,nums2;
    nums2.insert(nums2.end(),1);

    Solution solution;
    cout << solution.findMedianSortedArrays(nums1,nums2) << endl;

    return 0;
}
