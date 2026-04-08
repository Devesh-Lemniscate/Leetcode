/*
 * Problem 53: Maximum Subarray
 * Language: C++
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN, curr = 0;
        for(auto it: nums){
            if(curr < 0) curr = 0;
            curr += it;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};