class Solution {
    public int majorityElement(int[] nums) {
        int  n = nums.length;
        Arrays.sort(nums);
        int count = 0;
        int ans = nums[n/2];
        for(int i = 0 ; i < n; i++){
            if(nums[i] == ans) count++;
        }
        if(count < n/2) return 0;
        return ans;
    }
}
