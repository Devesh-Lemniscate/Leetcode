/*
 * Problem 600: Non-negative Integers without Consecutive Ones
 * Language: C++
 */
class Solution {
private:
    string s;
    int dp[33][2][2];
    int solve(int idx, int prev, bool tight){
        if(idx == s.size()) return 1;
        if(dp[idx][prev][tight] != -1) return dp[idx][prev][tight];
        int upperBound = (tight) ? s[idx]-'0' : 1; 
        int res = 0;
        for(int index = 0; index <= upperBound; index++){
            if(prev == 1 && index == prev) continue;
            bool nextTight = (tight && (index == upperBound));
            res += solve(idx+1, index, nextTight);
        }   
        return dp[idx][prev][tight] = res;
    }
public:
    int findIntegers(int n) {
        s = bitset<32>(n).to_string();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 1);
    }
};