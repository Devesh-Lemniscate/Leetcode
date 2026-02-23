/*
 * Problem 1461: Check If a String Contains All Binary Codes of Size K (POTD)
 * Language: C++
 */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        string str;
        for(int i = 0; i < k && i < s.size(); i++){
            str.push_back(s[i]);
        }
        st.insert(str);
        for(int i = k; i < s.size(); i++){
            str.push_back(s[i]);
            str.erase(0,1);
            st.insert(str);
        }
        return st.size() == pow(2, k);
    }
};