class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int, int> mp;
            int mn = INT_MAX;
            for(auto ele: nums){
                mp[ele]++;
                mn = min(mn, ele);
            }
            if(mn<k) return -1;
            else if(mn==k) return mp.size()-1;
            else return mp.size();
        }
    };