/*
 * Problem 3518: Smallest Palindromic Rearrangement II (POTD)
 * Language: C++
 */
#define ll long long
class Solution {
private:
    ll nCr(int n, int r, ll limit){
        if(r < 0 || r > n) return 0;
        if(r == 0 || r == n) return 1;
        if(r > n-r) r= n-r;
        ll res = 1;
        for(int i = 1; i <= r; i++){
            res = res * (n-i+1)/i;
            if(res >= limit) return limit;
        }
        return res;
    }
    ll countPerm(vector<int> &freq, ll limit){
        int total = accumulate(freq.begin(), freq.end(), 0);
        ll ways = 1;
        for(auto f: freq){
            if(f > 0){
                ll curr = nCr(total, f, limit);
                ways = min(limit, ways * curr);
                total -= f;
            }
        }
        return ways;
    }
public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26), halfCount(26);
        for(auto c: s) count[c-'a']++;
        string mid ="";
        for(int i = 0; i < 26; i++){
            halfCount[i] = count[i]/2;
            if(count[i] & 1) mid += (char)(i + 'a');
        }
        ll limit = k + 1LL;
        ll total = countPerm(halfCount, limit);
        if(total < k) return "";

        int n = accumulate(halfCount.begin(), halfCount.end(), 0);
        string left = "";

        for(int i = 0; i < n; i++){
            for (int j = 0; j < 26; j++) {
                if (halfCount[j] == 0) continue;
                halfCount[j]--;
                ll ways = countPerm(halfCount, limit);
                if (ways >= k) {
                    left += (char)('a' + j);
                    break;
                } else {
                    k -= ways;
                    halfCount[j]++; 
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};