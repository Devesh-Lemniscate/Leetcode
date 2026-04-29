/*
 * Problem 2246: Longest Path With Different Adjacent Characters
 * Language: C++
 */
class Solution {
private:
    int dfs(int node, int par, vector<vector<int>> &adj, int &ans, string &s){
        int temp1 = 0, temp2 = 0;
        for(auto it: adj[node]){
            if(it != par){
                int child = dfs(it, node, adj, ans, s);
                if(child > temp1){
                    temp2 = temp1;
                    temp1 = child;
                }else if(child > temp2){
                    temp2 = child;
                }
            }
        }
        ans = max(ans, temp1+temp2+1);
        return temp1+1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        dfs(0, -1, adj, ans, s);
        return ans;
    }
};