/*
 * Problem 1872: Stone Game VIII (POTD)
 * Language: C++
 */
class Solution {
private:
    int n, dp[100005];
    int helper(int ind, vector<int> &nums){
        if(ind == n-1) return nums[n-1];
        if(dp[ind] != -1) return dp[ind];
        int next = helper(ind+1, nums);
        return dp[ind] = max(nums[ind] - next, next);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        for(int i = 1; i < stones.size(); i++){
            stones[i] += stones[i-1];
        }
        memset(dp, -1, sizeof(dp));
        return helper(1, stones);
    }
};