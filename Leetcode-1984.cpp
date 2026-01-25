/*
 * Problem 1984: Minimum Difference Between Highest and Lowest of K Scores (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = k-1;
        int mini = INT_MAX;
        while(right < nums.size()){
            mini = min(mini, nums[right]-nums[left]);
            left++; right++;
        }
        return mini;
    }
};