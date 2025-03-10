class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size(), temp = k, maxLen = INT_MIN;
            for(int i = 0, j = 0; i < n; i++){
                if(nums[i]==0)temp--;
                while(temp<0){
                    if(nums[j]==0)temp++;
                    j++;
                }
                maxLen = max(maxLen, i-j+1);
            }
            return maxLen;
        }
    };