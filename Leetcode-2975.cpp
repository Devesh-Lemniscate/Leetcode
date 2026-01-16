/*
 * Problem 2975: Maximum Square Area by Removing Fences From a Field (POTD)
 * Language: C++
 */
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<int> st;
        for(int i = 0; i < h.size(); i++){
            for(int j = 1; j < h.size(); j++){
                st.insert(h[j]-h[i]);
            }
        }
        ll maxi = -1;
        for(int i = 0; i < v.size(); i++){
            for(int j = 1; j < v.size(); j++){
                ll num = v[j]-v[i];
                if(st.find(num) != st.end()  && num!=0){
                    maxi = max(maxi, num*num*1LL);
                }
            }
        }
        return maxi%mod;
    }
};