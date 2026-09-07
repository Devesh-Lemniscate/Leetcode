/*
 * Problem 443: String Compression
 * Language: C++
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int idx = 0;
        int n = chars.size();
        for(int i = 1; i < n; i++){
            if(chars[i] == chars[i-1]) count++;
            else{
                if(count == 1){
                    chars[idx++] = chars[i-1];
                    continue;
                }
                chars[idx++] = chars[i-1];
                string temp = to_string(count);
                for(int j = 0; j < temp.size(); j++) chars[idx++] = temp[j];
                count = 1;
            }
        }
        if(count == 1){
            chars[idx++] = chars[n-1];
            return idx;
        }
        chars[idx++] = chars[n-1];
        string temp = to_string(count);
        for(int j = 0; j < temp.size(); j++) chars[idx++] = temp[j];
        return idx;
    }
};