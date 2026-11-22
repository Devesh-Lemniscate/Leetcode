/*
 * Problem 2124: Check if All A's Appears Before All B's (POTD)
 * Language: Java
 */
class Solution {
    public boolean checkString(String s) {
        boolean isOkay = true;
        for(int i = 0; i < s.length(); i++){
            if(isOkay && s.charAt(i) == 'a') continue;
            if(s.charAt(i) == 'b') isOkay = false;
            if(s.charAt(i) == 'a' && !isOkay) return false;
        }
        return true;
    }
}