/*
 * Problem 756: Pyramid Transition Matrix (POTD)
 * Language: C++
 */
class Solution {
private:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> mp2;
    bool helper(string &bottom, int idx, string &s){
        if(idx == bottom.size()-1) return solve(s);
        string str = "";
        str.push_back(bottom[idx]);
        str.push_back(bottom[idx+1]);
        if(!mp.count(str)) return false;
        for(auto it: mp[str]){
            s.push_back(it);
            if(helper(bottom, idx+1, s)) return true;
            s.pop_back();
        }
        return false;
    }
    bool solve(string &bottom){
        if(bottom.size()==1)return true;
        if(mp2.count(bottom)) return mp2[bottom];
        string s = "";
        bool ans = helper(bottom, 0, s);
        return mp2[bottom] = ans;
    }

public:

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        for(auto allow: allowed){
            string s;
            for(int i = 0; i < allow.size()-1; i++) s.push_back(allow[i]);
            mp[s].push_back(allow[allow.size()-1]);
        }
        return solve(bottom);
    }
};