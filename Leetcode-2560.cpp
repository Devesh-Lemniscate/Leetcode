class Solution {
    public:
        bool check(vector<int> &nums, int k, int mid, int n){
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid ){
                    k--;i++;
                }
                if(k==0)return true;
            }
            return false;
        }
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size();
            int low = INT_MAX, high = INT_MIN;
            for(int i = 0; i < n; i++){
                low = min(low, nums[i]);
                high = max(high, nums[i]);
            }
            int ans = 0;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(check(nums, k, mid, n)){
                    ans = mid;
                    high = mid-1;    
                }
                else low = mid+1;
            }
            return ans;
        }
    };