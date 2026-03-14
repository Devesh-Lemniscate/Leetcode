/*
 * Problem 1415: The k-th Lexicographical String of All Happy Strings of Length n (POTD)
 * Language: C++
 */
class Solution {
private:
    void helper(int n, int k, int &cnt, string &curr, string &res){
        if(curr.size() == n){
            cnt++;
            if(cnt == k){
                res = curr;
            }
            return;
        }
        for(int i = 0; i < 3; i++){
            char ch = 'a' + i;
            if(curr.size() && curr[curr.size()-1] == ch) continue;
            curr.push_back(ch);
            helper(n, k, cnt, curr, res);
            if(res.size()) return;
            curr.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string curr = "", res ="";
        int cnt = 0;
        helper(n, k, cnt, curr, res);
        return res;
    }
};