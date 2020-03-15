#include <iostream>
#include <vector>
using namespace std;

struct treeNode {
    char val;
    treeNode* lptr = NULL;
    treeNode* rptr = NULL;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result(0);
        if(n == 0) return result;
        else if(n == 1) {
            result.resize(1);
            result[1] = "()";
        }
        

    }
};