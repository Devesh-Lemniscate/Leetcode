class Solution {
    public:
        void helper(vector<int> &nums, int &sum, int xors, int i){
            if(i >= nums.size()){
                sum+=xors;
                return;
            }
            helper(nums, sum, xors^nums[i], i+1);
            helper(nums, sum, xors, i+1);
        }
        int subsetXORSum(vector<int>& nums) {
            int sum = 0;
            helper(nums, sum, 0, 0);
            return sum;
        }
    };