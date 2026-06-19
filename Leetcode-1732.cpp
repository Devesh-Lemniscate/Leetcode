/*
 * Problem 1732: Find the Highest Altitude (POTD)
 * Language: C++
 */
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, sum = 0;
        for(auto altitude: gain){
            sum += altitude;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};