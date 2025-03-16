class Solution {
    public:
        bool check(vector<int>& ranks, long long mid, int cars){
    
            for(auto ele: ranks){
                cars -= floor(sqrt(mid/ele));
                if(cars<=0) return true;
            }
            return false;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long low = 1, high = LLONG_MAX;
            long long ans = 0;
            while(low<=high){
                long long mid = low + (high-low)/2;
                if(check(ranks, mid, cars)){
                    ans = mid;
                    high = mid-1;
                }else low = mid+1;
            }
            return ans;
        }
    };