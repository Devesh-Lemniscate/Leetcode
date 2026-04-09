/*
 * Problem 149: Max Points on a Line
 * Language: C++
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            map<pair<int, int>, int> mp;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int num = points[i][0] - points[j][0];
                int den = points[i][1] - points[j][1];
                int com = gcd(num, den);
                if(com != 0){
                    num /= com;
                    den /= com;
                }
                if(den < 0){
                    num = -num;
                    den = -den;
                }
                mp[{num, den}]++;
                maxi = max(maxi, mp[{num, den}]);
            }
        }
        return maxi+1;
    }
};