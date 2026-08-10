/*
 * Problem 375: Guess Number Higher or Lower II
 * Language: C++
 */
class Solution {
private:
    int dp[205][205];

    int solve(int st, int end){
        if(st >= end) return 0;
        if(dp[st][end] != -1) return dp[st][end];
        int mini = INT_MAX;
        for(int i = st; i <= end; i++){
            mini = min(mini, i + max(solve(st, i-1), solve(i+1, end)));
        }
        return dp[st][end] = mini;
    }
public:
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(1, n);
    }
};