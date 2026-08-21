/*
 * Problem 3116: Kth Smallest Amount With Single Denomination Combination (POTD)
 * Language: C++
 */
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long n = coins.size();
        long long total = (1 << n) - 1; 

        long long low = 1, high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        //long long ans = high;

        while(low <= high){
            long long mid = low + (high - low)/2;
            long long count = 0;
            for(long long mask = 1; mask <= total; mask++){
                long long curr = 1;
                for(long long i = 0; i < n; i++){
                    if(mask & (1 << i)){
                        curr = curr * (long long)coins[i] / __gcd(curr, (long long)coins[i]);
                        if(curr > mid) break;
                    }
                }
                if(__builtin_popcount(mask) & 1) count += mid / curr;
                else count -= mid / curr;
            }
            if(count < k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
/*
2,7,11
2,4,6,8,10,12,14,16,18,20,22,24,26

2 3 5 7 11 13 17 19 23
*/