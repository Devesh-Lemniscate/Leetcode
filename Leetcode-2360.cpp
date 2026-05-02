/*
 * Problem 2360: Longest Cycle in a Graph
 * Language: C++
 */
class Solution {
private:
    void dfs(int u, int curr, vector<int>&edge, vector<int>&dis, vector<int>&vis, int &maxi){
        vis[u] = 1;
        dis[u] = curr;
        int next = edge[u];
        if(next != -1){
            if(!vis[next]){
                dfs(next, curr+1, edge, dis, vis, maxi);
            }else if(dis[next] != -1){
                maxi = max(maxi, curr-dis[next]+1);
            }
        }
        dis[u] = -1;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> dis(n, -1), vis(n, 0);
        int maxi = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i])dfs(i, 1, edges, dis, vis, maxi);
        }
        return maxi;
    }
};