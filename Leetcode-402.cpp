/*
 * Problem 402: Remove K Digits
 * Language: C++
 */
class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(nums.size()==k) return "0";
        string ans ="";
        for(int i=0;i<nums.size();i++){
            while(!ans.empty() && k>0 && ans.back()>nums[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(nums[i]);
        }
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i); 
        return ans.empty() ? "0" : ans;
    }
};