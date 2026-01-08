/*
 * Problem 1458: Max Dot Product of Two Subsequences (POTD)
 * Language: C++
 */
const int NEG_INF = -1e9+7;
class Solution {
private:
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i >= nums1.size() || j >= nums2.size()) return NEG_INF;
        if(dp[i][j] != -1) return dp[i][j];
        int mul = nums1[i] * nums2[j];
        int notTake = helper(i+1, j+1, nums1, nums2, dp);
        int curr = mul + max(0, notTake); 
        int takej = helper(i+1, j, nums1, nums2, dp);
        int takei = helper(i, j+1, nums1, nums2, dp);
        return dp[i][j] = max({curr, takej, takei});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(0, 0, nums1, nums2, dp);
    }
};        