/*
 * Problem 3043: Find the Length of the Longest Common Prefix (POTD)
 * Language: C++
 */
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto it: arr1){
            while(it){
                st.insert(it);
                it/=10;
            }
        }
        int maxi = 0;
        for(auto it: arr2){
            while(it > 0){
                if(st.find(it) != st.end()){
                    string s = to_string(it);
                    maxi = max(maxi, (int)s.size());
                    break;
                }
                it /= 10;
            }
        }
        return maxi;
    }
};