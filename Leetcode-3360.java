/*
 * Problem 3360: Stone Removal Game (POTD)
 * Language: Java
 */
class Solution {
    public boolean canAliceWin(int n) {
        boolean turn = false;
        int num = 10;
        while(n >= 0){
            if(n >= num) n-=num;
            else return turn;
            turn = !turn;
            num--;
        }
        return turn;
    }
}