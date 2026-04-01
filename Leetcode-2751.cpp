/*
 * Problem 2751: Robot Collisions (POTD)
 * Language: C++
 */
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> pos;
        vector<int> st;
        int n = healths.size();
        for(int i = 0; i < n; i++) pos.push_back({positions[i], healths[i], directions[i], i});
        sort(pos.begin(), pos.end());

        int i = 0;
        while(i < n && pos[i][2] == 'L') i++;
        for(; i < n; i++){
            if(pos[i][2] == 'R') st.push_back(i);
            else if(st.size()){
                if(pos[i][1] < pos[st.back()][1]){
                    pos[st.back()][1] -= 1;
                    pos[i][1] = 0;
                }else if(pos[i][1] > pos[st.back()][1]){
                    while(st.size() && pos[i][1] > pos[st.back()][1]){
                        pos[i][1] -= 1;
                        pos[st.back()][1] = 0;
                        st.pop_back();
                    }
                    if(st.size() && pos[i][1] == pos[st.back()][1]){
                        pos[i][1] = 0; 
                        pos[st.back()][1] = 0;
                        st.pop_back();
                    }
                    if(st.size() && pos[i][1] > 0){
                        pos[st.back()][1] -= 1;
                        pos[i][1] = 0;
                    }
                }else{
                    pos[i][1] = 0; 
                    pos[st.back()][1] = 0;
                    st.pop_back();
                }
            }
        } 
        vector<int> ans;
        sort(pos.begin(), pos.end(), [](auto &a, auto &b){
            return a[3] < b[3];
        });
        for(auto it: pos) if(it[1])ans.push_back(it[1]);
        return ans;
    }
};