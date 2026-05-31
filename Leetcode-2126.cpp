/*
 * Problem 2126: Destroying Asteroids (POTD)
 * Language: C++
 */
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < asteroids.size(); i++){
            if(mass >= asteroids[asteroids.size() - 1]) break;
            if(asteroids[i] <= mass) mass += asteroids[i];
            else return false;
        }
        return true;
    }
};