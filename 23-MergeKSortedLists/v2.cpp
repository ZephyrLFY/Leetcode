#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* temp = NULL;
        unordered_multimap<int, ListNode*> table;
        vector<int> nums(0);
        int len = lists.size();
        if(len == 0) return NULL;
        else if(len == 1) return lists[0];
        // 创建Hash Map
        for(int i = 0; i < len; i++) {
            while(lists[i] != NULL) {
                table.insert({lists[i]->val, lists[i]});
                nums.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        set<int>s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        sort(nums.begin(), nums.end());
        bool first = true;
        for(int i = 0; i < nums.size(); i++) {
            auto range = table.equal_range(nums[i]);
            for(auto it = range.first; it != range.second; it++) {
                if(first) {
                    result = it->second;
                    temp = result;
                    first = false;
                }
                else {
                    temp->next = it->second;
                    temp = temp->next;
                }
            } 
        }
        temp = NULL;
        return result;
    }
};

int main()
{
    Solution solu;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(2);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(1);
    l2->next->next = new ListNode(2);
    vector<ListNode*> input = {l1, l2};
    ListNode* result = solu.mergeKLists(input);
    while(result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}