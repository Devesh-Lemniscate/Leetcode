/*
 * Problem 1340: Jump Game V (POTD)
 * Language: C++
 */
class Solution {
private:
    int helper(int idx, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[idx] != -1) return dp[idx];
        
        int maxi = 1;
        
        for (int i = idx + 1; i <= idx + d && i < arr.size(); i++) {
            if (arr[i] >= arr[idx]) break;
            maxi = max(maxi, 1 + helper(i, arr, d, dp));
        }
        
        for (int i = idx - 1; i >= idx - d && i >= 0; i--) {
            if (arr[i] >= arr[idx]) break;
            maxi = max(maxi, 1 + helper(i, arr, d, dp));
        }
        
        return dp[idx] = maxi;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, helper(i, arr, d, dp));
        }
        
        return maxi;
    }
};