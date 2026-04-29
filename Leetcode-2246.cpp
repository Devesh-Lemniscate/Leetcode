/*
 * Problem 2246: Longest Path With Different Adjacent Characters
 * Language: C++
 */
class Solution {
private:
    void dfs(int node, int par, vector<vector<int>> &adj){
        int temp = 0;
        for(auto it: adj[node]){
            if(it != par && s[it] != s[node]){
                temp++;
                dfs(it, node, adj);
            }
        }
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<pair<int, char>>> adj(n);
        for(int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        dfs(adj);        
    }
};