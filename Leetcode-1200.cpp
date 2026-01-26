/*
 * Problem 1200: Minimum Absolute Difference (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int len = nums.size();
        int mini = INT_MAX;

        for(int index = 1; index < len; index++) 
            mini = min(mini, nums[index] - nums[index-1]);

        vector<vector<int>> result;

        for(int index = 1; index < len; index++) 
            if(nums[index] - nums[index-1] == mini) 
                result.push_back({nums[index-1], nums[index]});
                
        return result;
    }
};