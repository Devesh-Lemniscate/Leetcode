/*
 * Problem 3453: Separate Squares I (POTD)
 * Language: C++
 */
class Solution {
private:
    bool check(const vector<vector<int>>& squares, double mid){
        double lower = 0, upper = 0;
        for(auto &it: squares){
            double bottom = it[1], side = it[2], top = bottom + side;
            if(top <= mid) lower += side * side;
            else if(bottom >= mid) upper += side * side;
            else {
                double below = mid - bottom, above = top - mid;
                lower += below * side;
                upper += above * side;
            }
        }
        return lower >= upper;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX, high = INT_MIN;
        for(auto it: squares){
            low = min(low, 1.0 * it[1]);
            high = max(high, 1.0 * (it[1] + it[2]));
        }
        double exp = 1e-5;
        while(high - low > exp){
            double mid = (low + high) / 2.0;
            if(check(squares, mid)) high = mid;
            else low = mid;
        }
        return low;
    }
};
