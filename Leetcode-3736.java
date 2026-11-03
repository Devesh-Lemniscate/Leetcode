/*
 * Problem 3736: Minimum Moves to Equal Array Elements III (POTD)
 * Language: Java
 */
class Solution {
    public int minMoves(int[] nums) {
        int maxElement = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxElement) 
                maxElement = nums[i];
        }
        int answer = 0;
        for(int i = 0; i < n; i++){
            answer += maxElement - nums[i];
        }
        return answer;
    }
}