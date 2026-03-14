/*
 * Problem 3296: Minimum Number of Seconds to Make Mountain Height Zero (POTD)
 * Language: C++
 */
class Solution {
private:
    bool check(long long mid, vector<int>& workerTimes, int mountainHeight){
        long long count = 0;
        for(auto time: workerTimes){
            long double K = (long double)2.0 * mid / time;
            long long n = (sqrt(1.0L + 4.0L * K) - 1.0L) / 2.0L;
            count += n;
            if (count >= mountainHeight) return true;
        }
        return count >= mountainHeight;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1e16;
        long long ans  = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(check(mid, workerTimes, mountainHeight)){
                ans = mid;
                high = mid-1;
            }else low = mid + 1;
        }
        return ans;
    }
};

 /*
 n* n +1 / 2 * xi <= mid
 */