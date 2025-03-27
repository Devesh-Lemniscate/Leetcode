class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int cnt = 0, n = nums.size();
            unordered_map<int, int> mp;
            for(auto ele: nums) mp[ele]++;
            int mx = INT_MIN, num = 0;
            for(auto ele: mp) if(ele.second > mx){
                mx = ele.second;
                num = ele.first;
            }
            for(int i = 0; i < n; i++){
                if(nums[i]==num){
                    cnt++;
                }
                int x = cnt, y = mx-cnt;
                if(x>(i+1)/2 && y>(n-i-1)/2) return i;
            }
            return -1;
        }
    };