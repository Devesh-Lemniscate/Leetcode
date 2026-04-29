/*
 * Problem 2246: Longest Path With Different Adjacent Characters
 * Language: C++
 */
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<pair<int, char>>> adj(n);
        for(int i = 1; i < n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }
};