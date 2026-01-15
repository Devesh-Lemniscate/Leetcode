/*
 * Problem 2943: Maximize Area of Square Hole in Grid (POTD)
 * Language: C++
 */
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        int maxih = 0, maxiv = 0, curr = 1;
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        for(int i = 1; i < h.size(); i++){
            if(h[i] == h[i-1]+1) curr++;
            else{
                maxih = max(maxih, curr);
                curr = 1;
            }
        }
        maxih = max(maxih, curr);
        curr = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] == v[i-1]+1) curr++;
            else{
                maxiv = max(maxiv, curr);
                curr = 1;
            }
        }
        maxiv = max(maxiv, curr);
        int maxi = min(maxih, maxiv);
        maxi++;
        return maxi * maxi;
    }
};