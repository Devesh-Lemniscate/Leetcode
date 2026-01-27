/*
 * Problem 3650: Minimum Cost Path with Edge Reversals (POTD)
 * Language: C++
 */
#define pii pair<int, int>
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2*it[2]});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        unordered_set<int> vis;
        pq.push({0, 0});
        while(pq.size()){
            auto [dist, node] = pq.top(); pq.pop();
            if(node == n-1) return dist;
            if(vis.find(node) != vis.end()) continue;
            vis.insert(node);
            for(auto &it: adj[node]){
                if(dis[it.first] > dist + it.second){
                    pq.push({dist + it.second, it.first});
                    dis[it.first] = dist + it.second;
                }
            }
        }        
        return -1;
    }
};