/*
 * Problem 1344: Angle Between Hands of a Clock (POTD)
 * Language: C++
 */
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double degree = abs(30.0 * (double)hour - 5.5 * (double)minutes);
        return min(degree, 360.0-degree);
    }
};