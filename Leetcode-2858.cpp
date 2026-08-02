/*
 * Problem 2858: Minimum Edge Reversals So Every Node Is Reachable
 * Language: C++
 */
class Solution {
private:
    void dfs1(int node, int par, vector<vector<pair<int, int>>> &adj, int &ans){
        for(auto [v, cost] : adj[node]){
            if(v != par){
                ans += cost;
                dfs1(v, node, adj, ans);
            }
        }
    }
    void dfs2(int node, int par, vector<vector<pair<int, int>>> &adj, vector<int> &ans){
        for(auto [neigh, cost]: adj[node]){
            if(neigh != par){
                if(cost == 1){
                    ans[neigh] = ans[node]-1;
                }else ans[neigh] = ans[node] + 1;
                dfs2(neigh, node, adj, ans);
            }
        }
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n-1; i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }   
        vector<int> ans(n, 0);
        dfs1(0, -1, adj, ans[0]);
        dfs2(0, -1, adj, ans);
        return ans;
    }
};