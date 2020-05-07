#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        return helper(version1, version2, 0, 0, len1, len2);
    }

    int helper(string& version1, string& version2, int i, int j, int len1, int len2) {
        if (i >= len1 && j >= len2) return 0;
        int comp1 = 0, comp2 = 0;
        
        while (i < len1 && version1[i] != '.')
            comp1 = comp1 * 10 + version1[i++] - '0';
        while (j < len2 && version2[j] != '.')
            comp2 = comp2 * 10 + version2[j++] - '0';
        if (comp1 > comp2) return 1;
        else if (comp1 < comp2) return -1;
        return helper(version1, version2, i + 1, j + 1, len1, len2);
    }
};