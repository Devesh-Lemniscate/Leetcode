/*
 * Problem 1807: Evaluate the Bracket Pairs of a String
 * Language: C++
 */
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++) mp[knowledge[i][0]] = knowledge[i][1];
        int i = 0;
        string ans;
        while(i < n){
            if(s[i] == '('){
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp.push_back(s[i]);
                    i++;
                }
                if(mp.count(temp))ans+=mp[temp];
                else ans.push_back('?');
                i++;
            }else{
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};