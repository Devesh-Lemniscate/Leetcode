class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int n = nums.size(), cnt = 0;
            for(int i = 0; i < n; i++){
                if(i > 0 && nums[i] == nums[i-1]) continue;
                if(binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k)) cnt++;
            }
            return cnt;
        }
    };