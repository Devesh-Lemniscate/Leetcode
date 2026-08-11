/*
 * Problem 2996: Smallest Missing Integer Greater Than Sequential Prefix Sum (POTD)
 * Language: C++
 */
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = 0;
        int  n = nums.size();
        if(n == 1) return 1+nums[0];
        int curr = 0;
        for(int i = 0; i < n-1; i++){
            curr += nums[i];
            if(nums[i] + 1 != nums[i+1])break;
            if(i == n-2) curr += nums[n-1];
        }
        
        unordered_set<int> st(nums.begin(), nums.end());
        while(1){
            if(!st.count(curr)) return curr;
            curr++; 
        }
        return ans;
    }
};