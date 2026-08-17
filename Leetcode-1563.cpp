/*
 * Problem 1563: Stone Game V (POTD)
 * Language: C++
 */
class Solution {
private:
    int n;
    int dp[505][505];
    int helper(int ind, int j, vector<int> &pref){
        if(ind == j) return 0;
        if(dp[ind][j] != -1) return dp[ind][j]; 
        int ans = 0;
        for(int i = ind; i < j; i++){
            int left = pref[i] - pref[ind-1];
            int right = pref[j] - pref[i];
            if(left > right) ans = max(ans, right + helper(i+1, j, pref));
            else if(right > left) ans = max(ans, left + helper(ind, i, pref));
            else ans = max(ans, left + max(helper(i+1, j, pref), helper(ind, i, pref)));
        }
        return dp[ind][j] = ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> pref(n+1, 0);
        pref[1] = stoneValue[0];
        for(int i = 2; i<=n; i++){
            pref[i] = pref[i-1] + stoneValue[i-1];
        }
        memset(dp, -1, sizeof(dp));
        return helper(1, n, pref);
    }
};