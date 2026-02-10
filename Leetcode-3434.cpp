/*
 * Problem 3434: Maximum Frequency After Subarray Operation
 * Language: C++
 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int countk = 0;
        for(auto& num: nums)
            if(num == k)
                countk++;

        int totalCount = 0;
        for(int currNum = 1; currNum <= 50; currNum++){
            if(currNum == k) continue;
            
            int currentCount = 0, maxGain = 0;
            for(int index = 0; index < nums.size(); index++){
                if(nums[index] == currNum) currentCount++;
                else if(nums[index] == k) currentCount--;
                
                if(currentCount < 0) currentCount = 0;
                if(currentCount > maxGain) maxGain = currentCount;
            }
            if(maxGain > totalCount) totalCount = maxGain;
        }
        
        return countk + totalCount;
    }
};