/*
 * Problem 1201: Ugly Number III
 * Language: C++
 */
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int low = 1, high = INT_MAX;
        long long x = (long long)a, y = (long long)b, z = (long long)c;
        long long xy = x*y/__gcd(x, y);
        long long yz = y*z/__gcd(y, z);
        long long zx = z*x/__gcd(z, x);
        long long xyz = x * yz/__gcd(x, yz);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = mid / x + mid / y + mid / z - mid / xy - mid / yz - mid / zx + mid / xyz;
            if(count < n) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};