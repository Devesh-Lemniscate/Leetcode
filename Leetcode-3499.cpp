/*
 * Problem 3499: Maximize Active Section with Trade I (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> nums;
        int n = s.size();
        if(n==1) return s[0] == '1';
        int sign = (s[0]=='1') ? 1 : -1;
        int ans = 0;
        int count = sign;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) count += sign;
            else{
                if(count < 0)nums.push_back(count);
                else ans += count;
                sign = (sign == 1) ? -1 : 1;
                count = sign;
            }
        }
        if(count < 0)nums.push_back(count);
        else ans += count;
        int maxi = 0;
        for(int i  = 1; i < nums.size(); i++){
            if(abs(nums[i] + nums[i-1]) > maxi) maxi = abs(nums[i] + nums[i-1]);
        }
        
        return ans + maxi;
    }
};