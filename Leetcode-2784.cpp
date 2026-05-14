/*
 * Problem 2784: Check if Array is Good (POTD)
 * Language: C++
 */
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int frequency[202];
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] >= len) return false;
            frequency[nums[i]]++;
        }
        if(frequency[len-1] != 2) return false;
        for(int i = 1; i < len-1; i++){
            if(frequency[i] != 1) return false;
        }
        return true;
    }
};