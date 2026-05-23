/*
 * Problem 1752: Check if Array Is Sorted and Rotated (POTD)
 * Language: C++
 */
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        if(nums.size()<=2) return true;
        for(int i=0; i<nums.size()-1;i++) if(nums[i]>nums[i+1]) cnt++;
        if(cnt>1) return false;
        else{
            if(cnt == 0 || (nums[0]>=nums[nums.size()-1])) return true;
        }
        return false;
    }
};