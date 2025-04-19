#define ll long long
class Solution {
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        ll ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int low = i+1, high = nums.size()-1;
            int idxLow = -1, idxHigh = -1, up = upper-nums[i], down = lower-nums[i];
            while(low <= high){
                int mid = low + (high-low)/2;
                if(nums[mid] <= up){
                    idxHigh = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                } // 0 1 4 4 5 7
            } 
            low = i+1, high = nums.size()-1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(nums[mid] >= down){
                    idxLow = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                } // 0 1 4 4 5 7
            } 
            cout << idxLow << " " << idxHigh << endl;
            if(idxLow==-1 || idxHigh==-1) continue;
            else ans+=(idxHigh-idxLow+1);
        }
        return ans;
    }
};