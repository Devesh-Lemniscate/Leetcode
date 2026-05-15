/*
 * Problem 153: Find Minimum in Rotated Sorted Array (POTD)
 * Language: C++
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        int m = 0;
        while(l<r){
            m = l + (r-l)/2;
            if( nums[r] > nums[m]) r=m;
            else if(nums[r] < nums[m]) l = m+1;
        } 
        return nums[l];
    }
};