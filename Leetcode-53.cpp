/*
 * Problem 53: Maximum Subarray
 * Language: C++
 */
class Solution {
private:
    int help(int left, int mid, int right, vector<int> &nums){
        int leftSum = INT_MIN, sum = 0;
        for(int i = mid; i >= left; i--){
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = INT_MIN; sum = 0;
        for(int i = mid+1; i <= right; i++){
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return leftSum + rightSum;
    }
    int helper(int left, int right, vector<int> &nums){
        if(left == right) return nums[left];
        int mid = left + (right-left)/2;
        int leftSum = helper(left, mid, nums);
        int rightSum = helper(mid+1, right, nums);
        int crossSum = help(left, mid, right, nums);
        return max({leftSum, rightSum, crossSum});
    }
public:
    int maxSubArray(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};