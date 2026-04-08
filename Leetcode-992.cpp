/*
 * Problem 992: Subarrays with K Different Integers
 * Language: C++
 */
class Solution {
private:
    int helper(vector<int> &nums, int k){
        int left = 0, right = 0;
        int len = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        while(right < len){
            mp[nums[right]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            count += right-left+1;
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};