/*
 * Problem 2246: Longest Path With Different Adjacent Characters
 * Language: C++
 */
class Solution {
public:
    vector<list<int>> adj;
    string s;
    int ans = 0;
    int helper(int curr) {
        int a = 0, b = 0;
        for (auto it : adj[curr]) {
            int len = helper(it);
            if (s[it] == s[curr]) continue;
            if (len >= a) {
                b = a;
                a = len;
            } else if (len > b) b = len;
        }
        ans = max(ans, a + b + 1);
        return 1 + a;
    }
    int longestPath(vector<int>& parent, string t) {
        adj.resize(parent.size());
        for (int i = 1; i < parent.size(); i++) adj[parent[i]].push_back(i);
        s = t;
        ans = 1;
        helper(0);
        return ans;
    }
};