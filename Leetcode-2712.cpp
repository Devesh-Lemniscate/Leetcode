/*
 * Problem 2712: Minimum Cost to Make All Characters Equal
 * Language: C++
 */
class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0, n = s.size();
        for(long long i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                ans += min(i, n-i);
            }
        }
        return ans;
    }
};
/*
0 1 1 2 2 3
3 3 2 2 1 1
*/