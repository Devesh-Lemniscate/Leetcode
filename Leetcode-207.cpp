/*
 * Problem 207: Course Schedule
 * Language: C++
 */
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < nums.size(); i++){
            adj[nums[i][1]].push_back(nums[i][0]);
        }
        vector<int> in(n);
        for(int num = 0; num < n; num++) for(auto it: adj[num]) in[it]++;
        queue<int> q;
        for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }

        return ans.size() == n;
    }
};