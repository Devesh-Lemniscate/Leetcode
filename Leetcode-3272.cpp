#define ll long long
class Solution {
public:
    ll ans = 0;
    set<map<int, int>> vis;

    ll convert(const vector<int>& pal) {
        ll res = 0;
        for (auto ele : pal) res = res * 10 + ele;
        return res;
    }

    ll fact(int n) {
        ll res = 1;
        for (int i = 2; i <= n; i++) res *= i;
        return res;
    }

    ll perm(const map<int, int>& mp, int n) {
        ll num = fact(n);
        for (auto ele : mp) num /= fact(ele.second);
        return num;
    }

    ll zero(map<int, int>mp, int n) {
        if (mp[0] == 0) return 0;
        mp[0]--;
        ll num = fact(n - 1);
        for (auto ele : mp) num /= fact(ele.second);
        return num;
    }

    void gen(vector<int>& pal, int l, int r, int k, int n) {
        if (l > r) {
            ll val = convert(pal);
            if (val % k == 0) {
                map<int, int> mp;
                for (ll i = val; i; i /= 10) {
                    mp[i % 10]++;
                }
                if (!vis.count(mp)) {
                    ans += perm(mp, n) - zero(mp, n);
                    vis.insert(mp);
                }
            }
            return;
        }
        for (int i = (l == 0 ? 1 : 0); i <= 9; i++) {
            pal[l] = i;
            pal[r] = i;
            gen(pal, l + 1, r - 1, k, n);
        }
    }

    long long countGoodIntegers(int n, int k) {
        vector<int> pal(n);
        gen(pal, 0, n - 1, k, n);
        return ans;
    }
};
