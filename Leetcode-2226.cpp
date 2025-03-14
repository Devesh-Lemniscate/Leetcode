class Solution {
    public:
        bool check(vector<int>& arr, long long k, int mid){
            long long sum = 0;
            for(auto ele: arr){
                sum+=ele/mid;
            }
            return sum>=k;
        }
        int maximumCandies(vector<int>& arr, long long k) {
            int l = 1, h = INT_MIN, ans = 0;
            for(auto ele: arr) h = max(h, ele);
            while(l<=h){
                int mid = l + (h-l)/2;
                if(check(arr, k, mid)){
                    l = mid+1;
                    ans = mid;
                }else h=mid-1;
            }
            return ans;
        }
    };