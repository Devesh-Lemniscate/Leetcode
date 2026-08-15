/*
 * Problem 3702: Longest Subsequence With Non-Zero Bitwise XOR (POTD)
 * Language: C++
 */
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xori = 0;
        bool allZero = true;
        for(auto num: nums){
            xori ^= num;
            if(num != 0) allZero = false;
        }
        if(allZero) return 0;
        if(xori == 0) return nums.size()-1;
        else return nums.size();
    }
};