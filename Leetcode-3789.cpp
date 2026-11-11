/*
 * Problem 3789: Minimum Cost to Acquire Required Items (POTD)
 * Language: C++
 */
#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 && need2 == 0) return 0;
        ll x1 = 0, x2 = need1, x3 = need2;
        ll a1 = x1 * costBoth + max(0LL, (ll)need1-x1)*cost1 + max(0LL, need2-x1)*cost2;
        ll a2 = x2 * costBoth + max(0LL, (ll)need1-x2)*cost1 + max(0LL, need2-x2)*cost2;
        ll a3 = x3 * costBoth + max(0LL, (ll)need1-x3)*cost1 + max(0LL, need2-x3)*cost2;
        return min({a1, a2, a3});
    }
};