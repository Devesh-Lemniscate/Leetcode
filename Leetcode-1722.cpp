/*
 * Problem 1722: Minimize Hamming Distance After Swap Operations (POTD)
 * Language: C++
 */
class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) parent[px] = py;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        for (auto &swap : allowedSwaps) {
            dsu.unite(swap[0], swap[1]);
        }
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int p = dsu.find(i);
            groups[p].push_back(i);
        }

        int ans = 0;
        for (auto &it : groups) {
            auto &indexes = it.second;
            unordered_map<int, int> freq;
            for (int idx : indexes) freq[source[idx]]++;
            for (int idx : indexes) {
                if (freq[target[idx]] > 0) freq[target[idx]]--;
                else ans++;
            }
        }
        return ans;
    }
};