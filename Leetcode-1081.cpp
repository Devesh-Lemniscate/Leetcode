/*
 * Problem 1081: Smallest Subsequence of Distinct Characters
 * Language: C++
 */
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastSeen(27, INT_MAX);
        vector<bool> seen(26, false);
        for(int index = 0; index < s.size(); index++){
            lastSeen[s[index]-'a'] = index;
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            int num = s[i] - 'a';
            if(seen[num]) continue;
            while(ans.size() && s[i] < ans[ans.size()-1] && lastSeen[ans[ans.size()-1]-'a'] > i){
                seen[ans[ans.size()-1] - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(num+'a');
            seen[num] = true;

        }
        return ans;
    }
};