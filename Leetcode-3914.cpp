/*
 * Problem 3914: Minimum Operations to Make Array Non Decreasing
 * Language: C++
 */
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long operations = 0;
        int len = nums.size();
        for(int index = len-2; index >= 0; index--){
            if(nums[index] > nums[index+1]){
                operations += (nums[index] - nums[index+1]);
            }
        }
        return operations;
    }
};