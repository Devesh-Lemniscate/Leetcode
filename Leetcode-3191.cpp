class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int ops = 0;
    
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) {
                    if (i + 2 >= n) {
                        return -1; 
                    }
                    nums[i] = 1;
                    nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
                    nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;
                    ops++;
                }
            }
            return ops;
        }
    };