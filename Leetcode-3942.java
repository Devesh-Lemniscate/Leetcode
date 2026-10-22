/*
 * Problem 3942: Minimum Operations to Sort a Permutation (POTD)
 * Language: Java
 */
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ind  = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                ind = i;
                break;
            }
        }
        boolean increasing = true, decreasing = true;
        for(int i = 0; i < n; i++){
            int nextInd = nums[(i+1) % n];
            if(nextInd != (nums[i] + 1) % n) increasing = false;
            if(nextInd != (nums[i] - 1 + n) % n) decreasing = false;
        } 

        int answer = Integer.MAX_VALUE;
        if(increasing)
            answer = Math.min(answer, Math.min(ind, n-ind+2));
        if(decreasing)
            answer = Math.min(answer, Math.min(ind+2, n-ind));
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}