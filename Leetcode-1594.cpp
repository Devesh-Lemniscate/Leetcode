/*
 * Problem 1594: Maximum Non Negative Product in a Matrix (POTD)
 * Language: C++
 */
#define ll long long
class Solution {
private:
    const ll mod = 1e9+7;
    pair<ll, ll> dp[15][15];
    bool vis[15][15];

    pair<ll, ll> solve(ll i, ll j, vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        
        if (i == n - 1 && j == m - 1) return {grid[i][j], grid[i][j]};
        if (vis[i][j]) return dp[i][j];

        ll maxi = -4e18, mini = 4e18;

        if (i + 1 < n) {
            auto [dmaxi, dmini] = solve(i + 1, j, grid);
            maxi = max({maxi, dmaxi * grid[i][j], dmini * grid[i][j]});
            mini = min({mini, dmaxi * grid[i][j], dmini * grid[i][j]});
        }
        if (j + 1 < m) {
            auto [rmaxi, rmini] = solve(i, j + 1, grid);
            maxi = max({maxi, rmaxi * grid[i][j], rmini * grid[i][j]});
            mini = min({mini, rmaxi * grid[i][j], rmini * grid[i][j]});
        }

        vis[i][j] = true;
        return dp[i][j] = {maxi, mini};
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));
        ll ans = solve(0, 0, grid).first; 
        if (ans < 0) return -1;
        return ans % mod;
    }
};