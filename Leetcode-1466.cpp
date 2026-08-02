/*
 * Problem 1466: Reorder Routes to Make All Paths Lead to the City Zero
 * Language: C++
 */
class Solution {
private:
    void dfs(int node, vector<int>& vis, int &cnt, vector<vector<pair<int, int>>> &adj){
        vis[node] = 1;
        for(auto [neigh, cost]: adj[node]){
            if(!vis[neigh]){
                cnt += cost;
                dfs(neigh, vis, cnt, adj);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto con: connections){
            int u = con[0], v = con[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        int cnt = 0;
        vector<int> vis(n, 0);
        dfs(0, vis, cnt, adj);
        return cnt;
    }
};