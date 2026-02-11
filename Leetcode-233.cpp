/*
 * Problem 233: Number of Digit One
 * Language: C++
 */
class Solution {
private:
    string s;
    int dp[11][2][11];
    int solve(int idx, bool tight, int cnt){
        if(idx == s.size()) return cnt;
        if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];
        int start = 0;
        int end = (tight == true) ? s[idx] - '0' : 9;
        int res = 0;
        for(int index = start; index <= end; index++){
            res += solve(idx+1, (tight && index == end), cnt + (index==1));
        }
        return dp[idx][tight][cnt] = res;
    }
public:
    int countDigitOne(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0);
    }
};