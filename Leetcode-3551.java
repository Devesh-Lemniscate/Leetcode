/*
 * Problem 3551: Minimum Swaps to Sort by Digit Sum (POTD)
 * Language: Java
 */
class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int[][] a = new int[n][3];
        for(int i = 0; i < n; i++){
            int sum = 0, num = nums[i];
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            a[i][0] = sum; a[i][1] = nums[i]; a[i][2] = i;
        }
        Arrays.sort(a, (p, q)->p[0] != q[0] ? Integer.compare(p[0], q[0]) : Integer.compare(p[1], q[1]));
        boolean[] vis = new boolean[n];
        int swaps = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] || a[i][2] == i) continue;
            int j = i, len = 0;
            while(!vis[j]){
                vis[j] = true;
                j = a[j][2];
                len++;
            }
            swaps += len-1;
        }
        return swaps;
    }
}