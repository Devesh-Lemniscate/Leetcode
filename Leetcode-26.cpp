/*
 * Problem 26: Remove Duplicates from Sorted Array
 * Language: C++
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        int idx = 0, n = nums.size();
        while(i < n && j < n){
            while(j < n && nums[j] == nums[j-1]) j++;
            if(j == n) break;
            idx++;
            nums[idx] = nums[j];
            j++;
        }
        return idx+1;
    }
};