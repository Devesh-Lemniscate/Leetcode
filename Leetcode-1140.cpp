/*
 * Problem 1140: Stone Game II (POTD)
 * Language: C++
 */
class Solution {
private:
    int dp[101][101];

    int helper(int ind, int m, vector<int> &piles){
        if(ind == piles.size()) return 0;
        if(dp[ind][m] != -1) return dp[ind][m];
        int ans = INT_MIN;
        for(int i = ind; i < min((int)piles.size(), ind + 2*m); i++){
            ans = max(ans, piles[ind] - helper(i+1, max(i-ind+1, m), piles));
        }
        return dp[ind][m] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        for(int i= piles.size()-2; i >= 0; i--){
            piles[i] += piles[i+1];
        }
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, 1, piles);
        return ans;
    }
};