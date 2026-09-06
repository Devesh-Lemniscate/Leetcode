/*
 * Problem 115: Distinct Subsequences (POTD)
 * Language: C++
 */
class Solution {
private:
    int dp[1001][1001];
    int n, m;
    int helper(int ind1, int ind2, string &s, string &t){
        if(ind1 == n) return 1;
        if(ind1 > n || ind2 >= m) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int ans = 0;
        if(s[ind1] == t[ind2]) ans += helper(ind1 + 1, ind2 + 1, s, t);
        ans += helper(ind1, ind2 + 1, s, t);
        return dp[ind1][ind2] = ans; 
    }
public:
    int numDistinct(string s, string t) {
        m = s.size(), n = t.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, t, s);
    }
};