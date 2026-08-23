/*
 * Problem 1927: Sum Game (POTD)
 * Language: C++
 */
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int left = 0, right = 0;
        int qleft = 0, qright = 0;
        for(int i = 0; i < n/2; i++){
            if(num[i] != '?') left += num[i]-'0';
            else qleft++;
            if(num[i+n/2] != '?') right += num[i+n/2]-'0';
            else qright++;
        }
        cout << left << " " << right << " " << qleft << " " << qright << endl;
        if((qleft + qright) % 2) return true;
        if(left == right && qleft == qright) return false;
        if(left > right){
            if(qleft >= qright) return true;
            qright -= qleft;
            if((left - right) == (qright/2)*9) return false;
            else return true;
        }else{
            if(qright >= qleft) return true;
            qleft -= qright;
            if((right - left) == (qleft/2)*9) return false;
            else return true; 
        }
    }
};