/*
 * Problem 3314: Construct the Minimum Bitwise Array I (POTD)
 * Language: C++
 */
class Solution {
private:
    int findBit(int num){
        int cnt = 0;
        while(num & 1){
            num >>= 1;
            cnt++;
        }
        return 1<<(cnt-1);
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int index = 0; index < n; index++){
            if(nums[index] % 2 == 0) continue;
            int num = findBit(nums[index]);
            ans[index] = nums[index]-num;
        }
        return ans;
    }
};