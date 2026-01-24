/*
 * Problem 392: Is Subsequence
 * Language: C++
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(),i, j;
        if(n > m) return false;
        for(i = 0, j = 0; i < n && j < m;) if(s[i] == t[j++]) i++;
        return ((i==n) ? true : false);
    }
};