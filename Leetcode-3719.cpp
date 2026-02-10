/*
 * Problem 3719: Longest Balanced Subarray I (POTD)
 * Language: C++
 */
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> st1, st2;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            st1.clear(); st2.clear();
            for(int j = i; j < nums.size(); j++){
                if(nums[j] % 2 == 0) st1.insert(nums[j]);
                else st2.insert(nums[j]);
                if(st1.size() == st2.size()) maxi = max(maxi, j-i+1);
            }
        }
        return maxi;
    }
};