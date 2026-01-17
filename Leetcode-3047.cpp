/*
 * Problem 3047: Find the Largest Area of Square Inside Two Rectangles (POTD)
 * Language: C++
 */
#define ll long long

class Solution {
public:
    ll largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll maxi = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++){
                int ix1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int iy1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int ix2 = min(topRight[i][0], topRight[j][0]);
                int iy2 = min(topRight[i][1], topRight[j][1]);
                if(ix1 < ix2 && iy1 < iy2) {
                    int width = ix2 - ix1;
                    int height = iy2 - iy1;
                    int curr = min(width, height);
                    if(curr > maxi) maxi = curr;
                }
            }
        }
        return maxi * maxi;
    }
};