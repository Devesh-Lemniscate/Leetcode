/*
 * Problem 560: Subarray Sum Equals K
 * Language: C++
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        if(n==1 && nums[0]==k) return 1;
        if(n==1) return 0;
        for(int i = 1; i < n; i++) nums[i] += nums[i-1];   
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            if(nums[i]==k) cnt++;
            if(m.find(nums[i]-k)!=m.end()) cnt+=m[nums[i]-k];
            m[nums[i]]++;
        }
        return cnt;
    }
};