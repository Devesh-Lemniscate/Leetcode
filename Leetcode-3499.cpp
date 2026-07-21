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
        int count = sign;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) count += sign;
            else{
                nums.push_back(count);
                sign = (sign == 1) ? -1 : 1;
                count = sign;
            }
        }
        nums.push_back(count);
        int ans = max(0, *max_element(nums.begin(), nums.end()));
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i-1] < 0 && nums[i+1] < 0){
                int temp = 0;
                if(i-2 >= 0) temp += nums[i-2];
                if(i+2 < nums.size()) temp += nums[i+2];
                ans = max(ans, abs(nums[i-1]) + abs(nums[i+1]) + nums[i] + temp); 
            }
        }
        return ans;
    }
};