class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[n/2];
        int count = 0;
        for(int i = 0 ; i < n ; i ++){
            if(nums[i] == ans){
                count ++;
            }
        }
        if(count > n/2) return ans;
        return 0;
    }
};