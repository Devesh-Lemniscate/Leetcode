/*
 * Problem 12: Integer to Roman
 * Language: C++
 */
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> arr{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string res = "";

        for (auto it : arr) {
            int val = it.first;
            string sym = it.second;
            if (num == 0) break;

            while (num >= val) {
                for(auto ch: sym)res.push_back(ch);
                num -= val;
            }
        }

        return res;        
    }
};