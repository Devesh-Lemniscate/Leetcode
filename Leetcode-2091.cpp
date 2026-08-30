/*
 * Problem 2091: Removing Minimum and Maximum From Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxIdx = -1, maxi = INT_MIN;
        int minIdx = -1, mini = INT_MAX;
        int len = nums.size();
        for(int ind = 0; ind < len; ind++){
            if(nums[ind] < mini){
                minIdx = ind;
                mini = nums[ind];
            }
            if(nums[ind] > maxi){
                maxIdx = ind;
                maxi = nums[ind];
            }
        }
        int operations = 1 + max(minIdx, maxIdx);
        operations = min(operations, len-min(maxIdx, minIdx));
        operations = min(operations, 1+minIdx+len-maxIdx);
        operations = min(operations, 1+maxIdx+len-minIdx);
        return operations;
    }
};