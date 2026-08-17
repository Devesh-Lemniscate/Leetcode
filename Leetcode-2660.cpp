/*
 * Problem 2660: Determine the Winner of a Bowling Game
 * Language: C++
 */
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0, score2 = 0;
        int n = player1.size();
        for(int ind = 0; ind < n; ind++){
            bool user1 = false, user2 = false;
            if(ind-1 >= 0){
                if(player1[ind-1] == 10) user1 = true;
                if(player2[ind-1] == 10) user2 = true;
            }
            if(ind-2 >= 0){
                if(player1[ind-2] == 10) user1 = true;
                if(player2[ind-2] == 10) user2 = true;
            }
            score1 += player1[ind];
            score2 += player2[ind];
            if(user1) score1 += player1[ind];
            if(user2) score2 += player2[ind];
        }
        if(score1 > score2) return 1;
        else if(score1 < score2) return 2;
        else return 0;
    }
};