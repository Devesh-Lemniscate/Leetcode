/*
 * Problem 3532: Path Existence Queries in a Graph I (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> connections(n, 0);
        int current = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                current++;
            }
            connections[i] = current;
        }
        int m = queries.size();
        int index = 0;
        vector<bool> answer(m);
        for(auto query: queries){
            if(connections[query[0]] == connections[query[1]]) answer[index++] = true;
            else answer[index++] = false;
        }
        return answer;
    }
};






