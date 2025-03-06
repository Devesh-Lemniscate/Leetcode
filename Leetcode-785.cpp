class Solution {
    public:
        bool check(int start,vector<vector<int>>& graph, vector<int> &color){
            queue<int> q;
            q.push(start);
            color[start]=0;
            while(q.size()){
                int node = q.front(); q.pop();
                for(auto ele: graph[node]){
                    if(color[ele]==-1){
                        color[ele] = (!color[node]);
                        q.push(ele);
                    }else if(color[ele] == color[node]) return false;
                }
            }
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            vector<int> color(graph.size(), -1);
            for(int i = 0; i < graph.size(); i++) if(color[i]==-1) if(!check(i, graph, color)) return false;
            return true;
        }
    };