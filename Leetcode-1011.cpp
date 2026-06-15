/*
 * Problem 1011: Capacity To Ship Packages Within D Days
 * Language: C++
 */
class Solution {
private:
    int check(int mid, vector<int>& weights){
        int count = mid, ans = 0;
        for(auto weight: weights){
            if(weight <= count) count -= weight;
            else{
                ans++;
                count = mid;
                count -= weight;
            }
        }
        return ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        high = accumulate(weights.begin(), weights.end(), 0);
        low = *max_element(weights.begin(), weights.end());
        int ans = 0;
        //cout << low << " " << high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid, weights) < days){
                high = mid-1;
                ans = mid;
            }else low = mid+1;
        }
        return ans;
    }
};
