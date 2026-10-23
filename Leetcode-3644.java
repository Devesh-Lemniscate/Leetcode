/*
 * Problem 3644: Maximum K to Sort a Permutation (POTD)
 * Language: Java
 */
class Solution {
    public int sortPermutation(int[] nums) {
        int n = nums.length;
        int answer = (1 << 20) - 1;
        boolean isSorted = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                isSorted = false;
                answer = answer & i;
            }
        }
        return isSorted ? 0 : answer;
    }
}