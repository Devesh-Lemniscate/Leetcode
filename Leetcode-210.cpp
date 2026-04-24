/*
 * Problem 210: Course Schedule II
 * Language: C++
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> adj[N];
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> inDegree(N, 0);
        for(int i = 0; i < N; i++){
            for(auto ele: adj[i]) inDegree[ele]++;
        }
        queue<int> q;
        for(int i = 0; i < N; i++) if(inDegree[i]==0)q.push(i);
        vector<int> ans;
        while(q.size()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto ele: adj[node]){
                inDegree[ele]--;
                if(!inDegree[ele]) q.push(ele);
            }
        }
        if(N==ans.size()) return ans;
        else return {};
    }
};