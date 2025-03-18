class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size(), len = 1;
            int i, j, temp = 0;
            for(i = 0, j = 0; i < n; i++){
                while(temp & nums[i]) temp^=nums[j++];
                temp|=nums[i];
                len = max(len, i-j+1);
            }
            return len;
        }
    };