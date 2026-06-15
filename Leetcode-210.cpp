/*
 * Problem 210: Course Schedule II
 * Language: C++
 */
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        for(auto it: arr){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> in(n);
        for(int i = 0; i < n; i++){
            for(auto it: adj[i]){
                in[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);
        vector<int> ans;
        while(q.size()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }
        if(ans.size() == n) return ans;
        return {};
    }
};