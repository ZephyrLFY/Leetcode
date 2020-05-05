#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		if (!wordBreak_139(s, wordDict)) return {};

		size_t validEnd = 0;
		vector<vector<string>> dp(s.size() + 1, vector<string>());

		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return {};
			if (i != 0 && dp[i].empty()) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) != 0) continue;
				validEnd = max(validEnd, newEnd);
				if (i == 0)
				{
					dp[newEnd].push_back(word);
					continue;
				}
				for (auto& d : dp[i])
				{
					dp[newEnd].push_back(d + " " + word);
				}
			}
		}

		return dp.back();
	}

	bool wordBreak_139(string& s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (string temp : wordDict) {
                int wordLen = temp.size();
                if (i >= wordLen && s.substr(i - wordLen, wordLen) == temp)
                    dp[i] = dp[i] || dp[i - wordLen];
            }
        }
        return dp[len];
    }
};