/*
 * Problem 2432: The Employee That Worked on the Longest Task
 * Language: C++
 */
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxi = 0, id = -1, prev = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i][1] - prev > maxi){
                maxi  = logs[i][1] - prev;
                id = logs[i][0];
            }
            if(logs[i][1] - prev == maxi){
                maxi  = logs[i][1] - prev;
                id = min(id, logs[i][0]);
            }
            prev = logs[i][1];
        }
        return id;
    }
};