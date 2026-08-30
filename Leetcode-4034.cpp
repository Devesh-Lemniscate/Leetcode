/*
 * Problem 4034: Minimum Bishop Moves to Reach Target
 * Language: C++
 */
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int startx = source[0], starty = source[1];
        int endx = target[0], endy = target[1];
        if((startx+starty)%2 != (endx+endy)%2) return -1;
        int tempx = startx, tempy = starty;
        while(tempx >= 1 && tempy <= 8){
            if(tempx == endx && tempy == endy) return 1;
            tempx--;
            tempy++;
        }
        tempx = startx, tempy = starty;
        while(tempx <= 8 && tempy >= 1){
            if(tempx == endx && tempy == endy) return 1;
            tempx++;
            tempy--;
        }
        tempx = startx, tempy = starty;
        while(tempx <= 8 && tempy <= 8){
            if(tempx == endx && tempy == endy) return 1;
            tempx++;
            tempy++;
        }
        tempx = startx, tempy = starty;
        while(tempx >= 1 && tempy >= 1){
            if(tempx == endx && tempy == endy) return 1;
            tempx--;
            tempy--;
        }


        return 2;
    }
};