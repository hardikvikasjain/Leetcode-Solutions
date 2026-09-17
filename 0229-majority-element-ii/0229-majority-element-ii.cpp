/* class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());

        int count = 1;

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i-1]) {
                count++;
            }
            else {
                if(count > n/3) {
                    ans.push_back(nums[i-1]);
                }

                count = 1;
            }
        }

        // Last element/group ka count check karna zaroori hai
        if(count > n/3) {
            ans.push_back(nums[n-1]);
        }

        return ans;
    }
};*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Find possible candidates
        for(int i = 0; i < n; i++) {

            if(nums[i] == candidate1) {
                count1++;
            }
            else if(nums[i] == candidate2) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Verify
        count1 = 0;
        count2 = 0;

        for(int num : nums) {
            if(num == candidate1)
                count1++;

            if(num == candidate2)
                count2++;
        }

        vector<int> ans;

        if(count1 > n/3)
            ans.push_back(candidate1);

        if(count2 > n/3 && candidate2 != candidate1)
            ans.push_back(candidate2);

        return ans;
    }
};