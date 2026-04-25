/*
 * Problem 3464: Maximize the Distance Between Points on a Square (POTD)
 * Language: C++
 */
using ll = long long;

class Solution {
public:
    ll map(int side, int x, int y) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }

    bool check(vector<ll> &t, int k, int side, int d) {
        int n = t.size();
        ll L = 4LL * side;
        vector<ll> circular(2 * n);

        for (int i = 0; i < n; i++) {
            circular[i] = t[i];
            circular[i + n] = t[i] + L;
        }

        for (int i = 0; i < n; i++) {
            int count = 1, idx = i;
            ll pos = circular[i]; 
            for (int cnt = 1; cnt < k; cnt++) {
                ll target = pos + d;
                auto it = lower_bound(circular.begin() + idx + 1, 
                circular.begin() + i + n, target);
                if (it == circular.begin() + i + n) {
                    count = -1; 
                    break;
                }
                idx = it - circular.begin();
                pos = circular[idx];
                count++;
            }
            if (count == k && (circular[i] + L - pos) >= d) return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k) {
        int n = points.size();
        int low = 0, high = 2 * side;
        vector<ll> t(n);

        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            t[i] = map(side, x, y);
        }
        sort(t.begin(), t.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(t, k, side, mid)) {
                low = mid + 1;
            } else high = mid - 1;
        }

        return high;
    }
};