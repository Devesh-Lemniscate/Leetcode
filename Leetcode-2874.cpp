class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int> left(n, 0), right(n, 0);
            for(int i = 0; i < n-1; i++){
                left[i+1] = max(left[i], nums[i]);
                right[n-i-2] = max(right[n-i-1], nums[n-i-1]);
            }
            long long int ans = 0;
            for(int j = 1; j < n-1; j++) ans = max(ans, (long long)((left[j]-nums[j])*(long long)right[j]));
            return ans;
        }
    };