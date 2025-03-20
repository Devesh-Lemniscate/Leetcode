class Solution {
    public:
        using int3=tuple<int, int, int>;
        const static int N=100000;
        vector<int3> adj[N];
        int root[N], cost[N];
        bitset<N> Evis;
    
        void dfs(int rt, int i, int wt) {
            root[i]=rt;
            cost[rt]&=wt; 
    
            for (auto& [j, w, eIdx] : adj[i]) {
                if (Evis[eIdx]) continue;
                Evis[eIdx]=1;
                dfs(rt, j, wt&w);
            }
        }
    
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            memset(root, -1, sizeof(int)*n);
            memset(cost, -1, sizeof(int)*n);
    
            int E=edges.size();
            for (int i=0; i<E; i++) {
                const int u=edges[i][0], v=edges[i][1], w=edges[i][2];
                adj[u].emplace_back(v, w, i);
                adj[v].emplace_back(u, w, i);
            }
    
            for (int i = 0; i<n; i++) {
                if (root[i]==-1) 
                    dfs(i, i, -1);
            }
            int m=query.size();
            vector<int> ans(m, -1);
            for (int i = 0; i < m; i++) {
                int s=query[i][0], t=query[i][1];
                if (root[s] == root[t]) 
                    ans[i] = cost[root[s]];
            }
            return ans;
        }
    };