/*
 * Problem 3863: Minimum Operations to Sort a String (POTD)
 * Language: Java
 */
class Solution {
    public int minOperations(String s) {
        char []chars = s.toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);
        int n = s.length();
        int maxi = 0;
        int mini = 0;
        boolean isSorted = true;

        if(n == 2){
            if(s.charAt(0) <= s.charAt(1)) return 0;
            else return -1;
        }

        for(int i = 0; i < n; i++){
            if(i > 0 && s.charAt(i-1) > s.charAt(i)){
                isSorted = false;
            }
            if(s.charAt(i) == sorted.charAt(0))
                mini++;
            
            if(s.charAt(i) == sorted.charAt(n-1))
                maxi++;
        }

        if(isSorted) return 0;

        if(s.charAt(0) == sorted.charAt(0) || s.charAt(n-1) == sorted.charAt(n-1)) return 1;
        if(maxi > 1 || mini > 1) return 2;
        if(s.charAt(0) == sorted.charAt(n-1) && s.charAt(n-1) == sorted.charAt(0)) return 3;

        return 2;
    }
}