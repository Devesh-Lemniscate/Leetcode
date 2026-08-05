/*
 * Problem 2360: Longest Cycle in a Graph
 * Language: C++
 */
class Solution {
    void dfs(int node, int currentCount, vector<int>& visited, vector<int> &distance, vector<int> &edges, int &largestCycle){
        visited[node] = 1;
        int nextNode = edges[node];
        distance[node] = currentCount;
        if(nextNode != -1){
            if(!visited[nextNode]){
                dfs(nextNode, currentCount + 1, visited, distance, edges, largestCycle);
            }else{
                largestCycle = max(largestCycle, currentCount - distance[nextNode] + 1);
            }
        }
        distance[node] = -1;
    }
public:
    int longestCycle(vector<int>& edges) {
        int totalNodes = edges.size();
        int largestCycle = -1;
        vector<int> visited(totalNodes, 0), distance(totalNodes, -1);
        for(int node = 0; node < totalNodes; node++){
            if(!visited[node]){
                dfs(node, 1, visited, distance, edges, largestCycle);
            }
        }
        return largestCycle;
    }
};