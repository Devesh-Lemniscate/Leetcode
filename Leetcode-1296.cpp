/*
 * Problem 1296: Divide Array in Sets of K Consecutive Numbers
 * Language: C++
 */
class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (auto card : hand) count[card]++;
        for (auto card : hand) {
            int start = card;
            while (count[start - 1] > 0) start--;
            while (start <= card) {
                while (count[start] > 0) {
                    for (int nextCard = start; nextCard < start + groupSize; nextCard++) {
                        if (count[nextCard] == 0) return false;
                        count[nextCard]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};