/*
 * Problem 3867: Sum of GCD of Formed Pairs
 * Language: C++
 */
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> gcds(n);
        long long maxi = INT_MIN;
        for(long long i = 0; i < n; i++){
            maxi = max(maxi, (long long)nums[i]);
            gcds[i] = __gcd((long long)nums[i], maxi);
        }
        sort(gcds.begin(), gcds.end());
        long long sum = 0;
        for(int i = 0, j = n-1; i < j; i++, j--){
            sum += __gcd(gcds[i], gcds[j]);
        }
        return sum;
    }
};