/*
 * Problem 1665: Minimum Initial Energy to Finish Tasks (POTD)
 * Language: C++
 */
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            return a[1]-a[0] > b[1]-b[0];
        });
        int ans = tasks[0][1];
        int prev = tasks[0][1] - tasks[0][0];
        for(int i = 1; i < tasks.size(); i++){
            if(tasks[i][1] > prev){
                ans += tasks[i][1]-prev;
                prev = tasks[i][1] - tasks[i][0];
            }else{
                prev -= tasks[i][0];
            }
        }
        return ans;
    }
};