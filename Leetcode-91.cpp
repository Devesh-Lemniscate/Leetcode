/*
 * Problem 91: Decode Ways
 * Language: C++
 */
class Solution {
int helper(int idx, string &s, vector<int> &dp){
    if(idx == s.size()) return 1;
    if(s[idx] == '0') return 0;
    if(dp[idx] != -1) return dp[idx];
    
    int ans = helper(idx+1, s, dp);

    if(idx+1 < s.size() && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))){
        ans += helper(idx+2, s, dp);
    }

    return dp[idx] = ans;
}
public:
    int numDecodings(string s) {
        int idx = 0;
        vector<int> dp(s.size()+1, -1);
        if(s[idx]=='0') return 0;
        return helper(idx, s, dp);
    }
};