/*
 * Problem 2904: Shortest and Lexicographically Smallest Beautiful String (POTD)
 * Language: C++
 */
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> indices;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '1') indices.push_back(i);
        }
        int mini = INT_MAX;
        string ans = "";
        for(int i = 0; i+k <= indices.size(); i++){
            if(indices[i+k-1] - indices[i] < mini){
                mini = indices[i+k-1] - indices[i];
                ans = s.substr(indices[i], mini+1);
            }else if(indices[i+k-1] - indices[i] == mini){
                string temp = s.substr(indices[i], mini+1);
                if(temp < ans) ans = temp;
            }
        }
        return ans;
    }
};