/*
 * Problem 488: Zuma Game
 * Language: C++
 */
class Solution {
private:
    unordered_map<string, int> memo;
    string clean(string board) {
        bool changed = true;
        while (changed) {
            changed = false;
            int n = board.length();
            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && board[j] == board[i]) {
                    j++;
                }
                if (j - i >= 3) {
                    board = board.substr(0, i) + board.substr(j);
                    changed = true;
                    break; 
                } else {
                    i = j;
                }
            }
        }
        return board;
    }

    int dfs(string board, string hand) {
        board = clean(board);
        
        if (board.empty()) return 0;
        if (hand.empty()) return INT_MAX;

        string state = board + "#" + hand;
        if (memo.count(state)) return memo[state];

        int mini = INT_MAX;

        for (int i = 0; i < hand.length(); i++) {
            if (i > 0 && hand[i] == hand[i - 1]) continue;

            char ch = hand[i];
            string next_hand = hand.substr(0, i) + hand.substr(i + 1);

            for (int j = 0; j <= board.length(); j++) {
                bool worth_inserting = false;
                
                if (j < board.length() && board[j] == ch) worth_inserting = true;
                if (j > 0 && board[j - 1] == ch) worth_inserting = true;
                
                if (j > 0 && j < board.length() && board[j - 1] == board[j] && board[j] != ch) {
                    worth_inserting = true;
                }

                if (!worth_inserting) continue;

                string next_board = board.substr(0, j) + ch + board.substr(j);
                int res = dfs(next_board, next_hand);
                
                if (res != INT_MAX) {
                    mini = min(mini, 1 + res);
                }
            }
        }

        return memo[state] = mini;
    }

public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int ans = dfs(board, hand);
        return ans == INT_MAX ? -1 : ans;
    }
};