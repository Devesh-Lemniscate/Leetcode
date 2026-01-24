/*
 * Problem 977: Squares of a Sorted Array
 * Language: C++
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 0, j = 0, idx = 0;
        while(i < n && nums[i] < 0) i++;
        j=i-1;
        while(i < n && j >= 0){
            if(abs(nums[j]) > nums[i]) ans[idx++] = nums[i]*nums[i++];
            else ans[idx++] = nums[j]*nums[j--];
        }
        while(i < n) ans[idx++] = nums[i]*nums[i++];
        while(j >= 0) ans[idx++] = nums[j]*nums[j--];
        return ans;
    }
};