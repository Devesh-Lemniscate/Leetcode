class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int tar) {
            int n = nums.size();
            for(int i = 0; i < n; i++){
                int num = tar-nums[i];
                int low = 0, high = n-1;
                while(low<=high){
                    int mid = low + (high-low)/2;
                    if(mid!=i && nums[mid]==num){
                        if(i>mid)return {mid+1, i+1};
                        else return {i+1, mid+1};
                    }  
                    else if(nums[mid] < num)low = mid+1;
                    else high = mid-1;
                }
            }
            return {};
        }
    };