/*
 * Problem 1392: Longest Happy Prefix
 * Language: C++
 */
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);
        int len = 0, i = 1;
        while(i < n){
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                }else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, lps[n-1]);
    }
};