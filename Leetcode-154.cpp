/*
 * Problem 154: Find Minimum in Rotated Sorted Array II (POTD)
 * Language: C++
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high){
            int mid = ((high + low) / 2);
            if(nums[mid] > nums[high]) low = mid+1;
            else if(nums[mid] < nums[high]) high = mid;
            else high--;
        }
        return nums[high];
    }
};