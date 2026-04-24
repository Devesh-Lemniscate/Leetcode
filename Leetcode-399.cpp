/*
 * Problem 399: Evaluate Division
 * Language: C++
 */
class Solution {
private:
    void dfs(string node, string &dest, unordered_map<string, unordered_map<string, double>> &adjacencyList, unordered_set<string>& visited, double& ans, double temp){
        if(visited.find(node) != visited.end()) return;
        visited.insert(node);
        if(node == dest) {
            ans = temp;
            return;
        }
        for(auto neighbour: adjacencyList[node]){
            dfs(neighbour.first, dest, adjacencyList, visited, ans, temp*neighbour.second);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adjacencyList;
        for(int index = 0; index < equations.size(); index++){
            string divide = equations[index][0];
            string dividing = equations[index][1];
            double value = values[index];
            adjacencyList[divide][dividing] = value;
            adjacencyList[dividing][divide] = 1.0 / value;
        }
        vector<double> answer;
        for(auto query: queries){
            string divide = query[0];
            string dividing = query[1];
            if(adjacencyList.find(divide) == adjacencyList.end() || adjacencyList.find(dividing) == adjacencyList.end()) answer.push_back(-1.0);
            else{
                unordered_set<string> visited;
                double ans = -1, temp = 1.0;
                dfs(divide, dividing, adjacencyList, visited, ans, temp);
                answer.push_back(ans);
            }
        }
        return answer;
    }
};