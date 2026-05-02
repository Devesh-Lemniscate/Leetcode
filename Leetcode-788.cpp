/*
 * Problem 788: Rotated Digits (POTD)
 * Language: C++
 */
class Solution {
private:
    string numStr;
    int memo[6][2][2];

    int findRotatedDigits(int currentIndex, bool isTight, bool hasChanged){
        if(currentIndex == numStr.length())
            return hasChanged ? 1 : 0;

        if(memo[currentIndex][isTight][hasChanged] != -1) 
            return memo[currentIndex][isTight][hasChanged];
        
        int start = 0;
        int end = isTight ? (numStr[currentIndex] - '0') : 9;
        int validDigits = 0;

        for(int index = start; index <= end; index++){
            if(index == 3 || index == 4 || index == 7) continue;

            bool newTight = (isTight && index == end);
            bool newChanged = hasChanged || (index == 2 || index == 5 || index == 6 || index == 9);

            validDigits += findRotatedDigits(currentIndex + 1, newTight, newChanged);
        }

        return memo[currentIndex][isTight][hasChanged] = validDigits;
    }

public:
    int rotatedDigits(int n) {
        numStr = to_string(n);
        memset(memo, -1, sizeof(memo));
        
        int validDigits = findRotatedDigits(0, true, false); 
        return validDigits;
    }
};