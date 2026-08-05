/*
 * Problem 3310: Remove Methods From Project (POTD)
 * Language: C++
 */
class Solution {
private:
    void dfs(vector<vector<int>> &adj, int node, unordered_set<int> &st){
        st.insert(node);
        for(auto it: adj[node]){
            if(!st.count(it)) dfs(adj, it, st);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto it: invocations){
            adj[it[0]].push_back(it[1]);
        }
        unordered_set<int> st;
        dfs(adj, k, st);
        vector<int> ans;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(!st.count(i)){
                for(int j = 0; j < adj[i].size(); j++){
                    if(st.count(adj[i][j])){
                        flag = true;
                    }
                }
            }
        }
        if(flag){
            for(int i = 0; i < n; i++) ans.push_back(i);
            return ans;
        }else{
            for(int i = 0; i < n; i++) if(!st.count(i)) ans.push_back(i);
            return ans;
        }
    }
};