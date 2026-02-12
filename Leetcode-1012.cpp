/*
 * Problem 1012: Numbers With Repeated Digits
 * Language: C++
 */
class Solution {
private:
    string s;
    int dp[11][2][2][1024];
    int solve(int idx, bool tight, bool lz, int mask){
        if(idx == s.size()) return 1;
        if(dp[idx][tight][lz][mask] != -1) return dp[idx][tight][lz][mask];
        int start = 0;
        int end = (tight) ? s[idx]-'0' : 9;
        int res = 0;
        for(int index = start; index <= end; index++){
            if(!lz && (mask & (1 << index))) continue;
            bool nextTight = tight && (index == end);
            bool nextLz = lz && (index == 0);
            int nextMask = (nextLz) ? 0 : (mask | (1 << index)); 
            res += solve(idx+1, nextTight, nextLz, nextMask);
        } 
        return dp[idx][tight][lz][mask] = res;
    }
public:
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return n-solve(0,1,1,0)+1;
    }
};