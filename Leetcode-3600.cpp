/*
 * Problem 3600: Maximize Spanning Tree Stability with Upgrades (POTD)
 * Language: C++
 */
class UnionFind {
public:
    vector<int> rank, root;
    UnionFind(int n) : rank(n, 1), root(n) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }
    bool unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] > rank[ry]) {
            root[ry] = rx;
        } else if (rank[rx] < rank[ry]) {
            root[rx] = ry;
        } else {
            root[rx] = ry;
            rank[ry] += 1;
        }
        return true;
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind initial_uf(n);
        int min_s = INT_MAX;
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (!must) continue;
            min_s = min(min_s, s);
            if (!initial_uf.unionSet(u, v)) return -1;
        }
        vector<int> baseRank = initial_uf.rank;
        vector<int> baseRoot = initial_uf.root;

        auto check = [&](int min_stability) -> bool {
            if (min_stability > min_s) return false;

            UnionFind uf(n);
            uf.rank = baseRank;
            uf.root = baseRoot;

            vector<pair<int,int>> upgrade;
            for (auto& e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if (must) continue;
                if (s >= min_stability) {
                    uf.unionSet(u, v);
                } else if (s * 2 >= min_stability) {
                    upgrade.emplace_back(u, v);
                }
            }

            int r = k; 
            for (auto& p : upgrade) {
                int u = p.first, v = p.second;
                if (uf.isConnected(u, v)) continue;
                if (!r) return false;
                uf.unionSet(u, v);
                --r;
            }

            int root0 = uf.find(0);
            for (int i = 1; i < n; ++i)
                if (uf.find(i) != root0) return false;
            return true;
        };

        int right = 0;
        for (auto& e : edges) right = max(right, e[2]);
        right *= 2;
        int left = -1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};