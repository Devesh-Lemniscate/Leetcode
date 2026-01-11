/*
 * Problem 152: Maximum Product Subarray
 * Language: C++
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int  maxi = nums[0], mini = nums[0], answer = nums[0];
        for(int index = 1; index < nums.size(); index++){
            int num = nums[index];
            if(num < 0) swap(maxi, mini);
            maxi = max(num, maxi*num);
            mini = min(num, mini*num);
            answer = max(answer, maxi);
        }
        return answer;
    }
};