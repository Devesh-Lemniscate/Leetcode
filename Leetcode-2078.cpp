/*
 * Problem 2078: Two Furthest Houses With Different Colors (POTD)
 * Language: C++
 */
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi = 0, len = colors.size();
        for(int i = 1; i < len; i++) if(colors[i] != colors[0]) maxi = max(maxi, i);
        for(int i = len-2; i >= 0; i--) if(colors[i] != colors[len-1]) maxi = max(maxi, len-1-i);
        return maxi; 
    }
};