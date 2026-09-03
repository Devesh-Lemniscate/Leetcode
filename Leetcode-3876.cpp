/*
 * Problem 3876: Construct Uniform Parity Array II (POTD)
 * Language: C++
 */
class Solution {
public:
    bool uniformArray(vector<int>& nums){
        int odd = 0, even = 0;
        int mini = INT_MAX;
        for(auto it: nums){
            if(it & 1) odd++;
            else even++;
            mini = min(mini, it);
        }
        int n = nums.size();
        if(odd == n || even == n) return true;
        long long countOdd = 0;
        if(mini % 2 == 0) return false;
        countOdd = odd + (long long)even*(long long)odd;
        return countOdd >= n;
    }
};