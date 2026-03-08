/*
 * Problem 1443: Minimum Time to Collect All Apples in a Tree
 * Language: C++
 */
class Solution {
public:
    vector<vector<int>> adj;
    int dfs(vector<bool>& hasApple,int node,int d,int prev){
        int result=0,temp;
        for(int &i:adj[node]){
            if(i!=prev){
                temp=dfs(hasApple,i,d+1,node);
                if(temp) result+=temp-d;
            }
        }
        return result||hasApple[node]?result+d:0; 
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(hasApple,0,0,-1)*2;
    }
};