/*
 * Problem 3847: Find the Score Difference in a Game
 * Language: C++
 */
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int multiplier = 1, difference = 0;
        for(int index = 0; index < nums.size(); index++){
            if(nums[index] & 1) multiplier *= -1;
            if((index + 1) % 6 == 0) multiplier *= -1;
            difference += multiplier * nums[index];
        }
        return difference;
    }
};