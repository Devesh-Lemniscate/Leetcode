class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> mp;
            for(auto ele : nums) mp[ele]++;
            bool flag = true;
            for(auto ele: mp) if(ele.second%2) flag = false;
            return flag;
        }
    };