class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size();
            int low = 0, high = n-1, mid = 0;
            while(low <= high){
                mid = low + (high-low)/2;
                if(nums[mid] < 0) low = mid+1;
                else high = mid-1;
            }
            int neg = low, pos = 0;
            low = 0, high = n-1;
            while(low <= high){
                mid = low + (high-low)/2;
                if(nums[mid] > 0) high = mid-1;
                else low = mid+1;
            }
            pos = n-low;
            return max(neg, pos);
        }
    };