/*
 * Problem 319: Bulb Switcher
 * Language: C++
 */
class Solution {
public:
    int bulbSwitch(int n) {
        int low = 0, high = n;
        int on = 0;
        while(low <= high){
            long long mid = ((high - low) >> 1) + low;
            if(mid * mid <= n){
                on = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return on;
    }
};