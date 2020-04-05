#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> buf; //哈希表判断是否存在这个组合，其中int表示下标索引
        int index = 0; //将哈希表中的int与答案数组的下标联系起来
        string temp;
        for(auto str : strs) {
            temp = str;
            sort(str.begin(), str.end()); //排序
            if(buf.count(str)) res[buf[str]].push_back(temp); //有这个组合
            else {
                vector<string> single(1, temp); //新建这个组合，添加到结果集
                res.push_back(single);
                buf[str] = index++; //答案索引++
            }
        }
        return res;
    }
};