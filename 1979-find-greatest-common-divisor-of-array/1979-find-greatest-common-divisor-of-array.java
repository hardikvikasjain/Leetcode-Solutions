class Solution {
    public int findGCD(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int b = nums[0];
        int a = nums[n-1];
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
return a;
    }
}