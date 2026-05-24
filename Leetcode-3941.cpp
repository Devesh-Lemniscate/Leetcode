/*
 * Problem 3941: Password Strength
 * Language: C++
 */
class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> low, up, digit, special;
        for(int i = 0; i < 26; i++){
            low.insert(char('a'+i));
            up.insert(char('A'+i));
            if(i < 10) digit.insert(char(i+'0'));
        }
        special.insert('!');
        special.insert('@');
        special.insert('#');
        special.insert('$');
        int strength = 0;
        for(auto pass: password){
            if(low.count(pass)){
                strength += 1;
                low.erase(pass);
            }
            if(up.count(pass)){
                strength += 2;
                up.erase(pass);
            }
            if(digit.count(pass)){
                strength += 3;
                digit.erase(pass);
            }
            if(special.count(pass)){
                strength += 5;
                special.erase(pass);
            }
        }
        return strength;
    }
};