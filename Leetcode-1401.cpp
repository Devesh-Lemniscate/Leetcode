/*
 * Problem 1401: Circle and Rectangle Overlapping (POTD)
 * Language: C++
 */
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = max(x1, min(x2, xCenter)) - xCenter;
        int y = max(y1, min(y2, yCenter)) - yCenter;
        return x*x + y*y <= radius * radius;
    }
};