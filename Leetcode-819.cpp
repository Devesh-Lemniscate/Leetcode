/*
 * Problem 819: Most Common Word
 * Language: C++
 */
class Solution {
private:    
    bool check(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    string lower(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        }
        return s;
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        unordered_set<string> st(banned.begin(), banned.end());
        int n = paragraph.size();
        int maxi = -1;
        string ans;
        for(int i = 0; i < n; ){
            string temp;
            while(i < n && check(paragraph[i])){
                temp.push_back(paragraph[i++]);
            }
            temp = lower(temp);
            if(!st.count(temp))freq[temp]++;
            if(freq[temp] > maxi){
                maxi = freq[temp];
                ans = temp;
            }
            while(i < n && !check(paragraph[i])) i++;
        }
        return ans;
    }
};