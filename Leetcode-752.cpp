/*
 * Problem 752: Open the Lock
 * Language: C++
 */
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        unordered_set<string> st(deadends.begin(), deadends.end()), vis;
        if(st.count("0000")) return -1;
        q.push({"0000", 0});
        while(!q.empty()){
            string s = q.front().first; 
            int steps = q.front().second;q.pop();
            if(st.count(s) || vis.count(s)) continue;
            if(s == target) return steps;
            vis.insert(s);
            for(int i = 0; i < 4; i++){
                string s1 = s, s2 = s;
                s1[i] = ((s1[i] - '0' + 1) % 10) + '0';
                q.push({s1, steps+1});
                s2[i] = ((s2[i] -'0' - 1 + 10) % 10) + '0';
                q.push({s2, steps+1});
            }
        }
        return -1;
    }
};