/*
 * Problem 53: Maximum Subarray
 * Language: C++
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(auto it: nums){
            sum=max(it, sum+it);
            maxi = max(maxi, sum);
        }
        return maxi;   
    }
};