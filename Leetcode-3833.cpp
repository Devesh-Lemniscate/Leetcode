/*
 * Problem 3833: Count Dominant Indices
 * Language: C++
 */
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixSum(len, 0);
        prefixSum[0] = nums[0];
        
        for(int index = 1; index < len; index++)
            prefixSum[index] = nums[index] + prefixSum[index-1];

        int count = 0;
        for(int index = 0; index < len-1; index++){
            int sum = prefixSum[len-1] - prefixSum[index];
            if((sum / (len - index - 1)) < nums[index]) count++;
        }

        return count;
    }
};