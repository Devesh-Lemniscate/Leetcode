/*
 * Problem 396: Rotate Function (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < len; i++) prefix[i] = nums[i] + prefix[i-1];
        int maxi = 0, sum = 0;
        for(int i = 0; i < len; i++) maxi += i*nums[i];
        sum = maxi;
        for(int i = 1; i < len; i++){
            sum += (len-1)*nums[i-1];
            if(i-2 >= 0)sum -= prefix[i-2];
            sum -= (prefix[len-1]-prefix[i-1]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};