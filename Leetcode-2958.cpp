/*
 * Problem 2958: Length of Longest Subarray With at Most K Frequency (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0, len = nums.size();
        int maxi = INT_MIN;
        unordered_map<int, int> frequency;
        while(left < len && right < len){
            frequency[nums[right]]++;
            if(frequency[nums[right]] > k){
                while(left < right && nums[left] != nums[right]){ 
                    frequency[nums[left]]--;
                    left++;
                }
                frequency[nums[left]]--;
                left++;
            }
            maxi = max(maxi, right-left+1);
            right++;
        }
        maxi = max(maxi, right-left);
        return maxi;
    }
};