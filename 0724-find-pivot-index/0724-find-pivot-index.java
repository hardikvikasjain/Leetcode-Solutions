/*class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 0 ; i < n ; i ++){
        leftsum += nums[i];
        rightsum += nums[n-i-1];
        if(leftsum == rightsum) return i;
        }
        return -1;
    }
}*/
class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int total = 0;
        int left = 0;
        for (int num : nums) {
            total += num;
        }
        for (int i = 0; i < n; i++) {
            int right = total - left - nums[i];
            if (left == right)
                return i;
            left += nums[i];
        }
        return -1;
    }
}