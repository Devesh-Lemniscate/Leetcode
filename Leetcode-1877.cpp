/*
 * Problem 1877: Minimize Maximum Pair Sum in Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mini = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++) mini = max(mini, nums[i]+nums[n-i-1]);
        return mini;
    }
};
