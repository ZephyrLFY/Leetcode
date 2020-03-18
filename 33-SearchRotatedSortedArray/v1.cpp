#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;

        while(left <= right){
            if(nums[mid] == target) return mid;

            if(nums[left] <= nums[mid]) {  //左边升序
                if(target >= nums[left] && target <= nums[mid]) {//在左边范围内
                    right = mid-1;
                }
                else {//只能从右边找
                    left = mid+1;
                }
            }
            else { //右边升序
                if(target >= nums[mid] && target <= nums[right]) {//在右边范围内
                    left = mid +1;
                }
                else {//只能从左边找
                    right = mid-1;
                }

            }
            mid = (left + right) / 2;
        }
        return -1;  //没找到
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {1,3};
    cout << solu.search(nums, 0) << endl;
    return 0;
}