/*
 * Problem 462: Minimum Moves to Equal Array Elements II (POTD)
 * Language: Java
 */
class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int answer = 0;
        for(int i = 0; i < n/2; i++){
            answer += (nums[n-i-1] - nums[i]);
        }
        return answer;
    }
}