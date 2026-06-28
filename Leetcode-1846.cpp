/*
 * Problem 1846: Maximum Element After Decreasing and Rearranging (POTD)
 * Language: C++
 */
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums[0] = 1;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i]-1 > nums[i-1]) 
                nums[i] = nums[i-1] + 1;

        return nums.back();
    }
};