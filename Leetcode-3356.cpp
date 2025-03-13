class Solution {
    public:
        bool check(vector<int> nums, vector<vector<int>> &queries, int mid){
            int n = nums.size();
            vector<int> arr(n+1);
            for(int i = 0; i < mid; i++){
                int left = queries[i][0], right = queries[i][1], val = queries[i][2];
                arr[left]-=val;
                if(right+1 < n) arr[right+1]+=val;
            }
            int curr = 0;
            for(int i = 0; i < n; i++){
                curr += arr[i];
                nums[i] += curr;
                if(nums[i] > 0) return false;
            }
            return true;
        }
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int m = queries.size();
            int low = 0, high = m, ans = -1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(check(nums, queries, mid)){
                    ans = mid;
                    high = mid-1;
                }else low = mid+1;
            }
            return ans;
        }
    };