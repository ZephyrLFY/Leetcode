#include <iostream>
#include <vector>
using namespace std;

class Trie {
public:
    vector<Trie*> next;
    Trie() : next(2, 0) {}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        for (int num : nums) {
            Trie* node = root;
            for(int i = 30; i >= 0; --i)
            {
                int bt = num >> i & 1;
                if(node->next[bt] == nullptr) node->next[bt] = new Trie();
                node = node->next[bt];
            }
        }

        int res = 0;
        for(int num : nums)
        {
            Trie* node = root;
            int sum = 0;
            for(int i = 30; i >= 0; i--)
            {
                int bt = num >> i & 1;  
                // 如果bt==1则贪心的去找0异或  否则找1异或
                if(bt == 1)
                {
                    sum += node->next[0] != nullptr ? 1 << i : 0 ;
                    node = node->next[0] != nullptr ? node->next[0] : node->next[1];
                }
                else
                {
                    sum += node->next[1] != nullptr ? 1 << i : 0 ;
                    node = node->next[1] != nullptr ? node->next[1] : node->next[0];
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};