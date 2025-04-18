class Solution {
    public:
        string countAndSay(int n) {
            if(n==1) return "1";
            string str = countAndSay(n-1);
            string ztr = "";
            int freq = 1;
            char ch = str[0];
            for(int i = 1; i < str.length(); i++){
                if(ch == str[i]) freq++;
                else{
                    ztr+=(to_string(freq)+ch);
                    freq = 1;
                    ch = str[i];
                }
            }
            ztr+=(to_string(freq)+ch);
            return ztr;
        }
    };