/*
 * Problem 3558: Number of Ways to Assign Edge Weights I (POTD)
 * Language: C++
 */
class Solution {
private:
    const int mod = 1e9+7;
    int modPow(long long num, long long exp){
        long long res = 1;
        while(exp > 0){
            if(exp & 1)res = res * num % mod;
            num = (num * num) % mod;
            exp /= 2;
        }
        return res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        queue<int> q;
        unordered_set<int> vis;
        q.push(1);
        vis.insert(1);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                int node = q.front();
                for(auto it: adj[node]){
                    if(!vis.count(it)){
                        q.push(it);
                        vis.insert(it);
                    }
                }
                q.pop();
            }
            count++;
        }

        return modPow(2, count-2);
    }
};