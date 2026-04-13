/*
 * Problem 1848: Minimum Distance to the Target Element (POTD)
 * Language: C++
 */
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                mini = min(mini, abs(start - i));
            }
        }
        return mini;
    }
};