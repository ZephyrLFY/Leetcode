#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    permuteRecursive(num, 0);
	    return result;
    }

	void permuteRecursive(vector<int> &num, int begin)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1);
		    // reset
		    swap(num[begin], num[i]);
		}
    }

private:
    vector<vector<int> > result;
    vector<int> path;
};