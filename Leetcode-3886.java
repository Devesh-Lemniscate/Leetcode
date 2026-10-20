/*
 * Problem 3886: Sum of Sortable Integers (POTD)
 * Language: Java
 */
class Solution {
    public int sortableIntegers(int[] nums) {
        int n = nums.length;
        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        ArrayList<Integer> divisors = new ArrayList<>();
        for(int i = 1; i <= Math.sqrt(n); i++){ 
            if(n % i == 0){
                divisors.add(i);
                if (i * i != n) {
                    divisors.add(n / i);
                }
            }
        }
        int sum = 0;
        for(int k: divisors){
            if(check(k, nums, sorted)){
                sum += k;
            }
        }
        return sum;
    }

    private boolean check(int k, int[] nums, int[] sorted){
        int n = nums.length;
        for(int i = 0; i < n; i+=k){
            int j = i+k;
            Map<Integer, Integer> counts = new HashMap<>();
            for (int l = i; l < j; l++) {
                counts.put(nums[l], counts.getOrDefault(nums[l], 0) + 1);
                counts.put(sorted[l], counts.getOrDefault(sorted[l], 0) - 1);
            }
            for (int count : counts.values()) {
                if (count != 0) return false;
            }

            int drops = 0;
            for (int l = 0; l < k; l++) {
                int curr = nums[i + l];
                int next = nums[i + (l + 1) % k];
                if (curr > next) {
                    drops++;
                }
            }
            if (drops > 1) return false;
        }
        return true;
    }
}