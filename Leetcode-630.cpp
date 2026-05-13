/*
 * Problem 630: Course Schedule III
 * Language: C++
 */
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int sum = 0;
        for(auto it: courses){
            sum += it[0];
            pq.push(it[0]);
            if(sum > it[1]){
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};