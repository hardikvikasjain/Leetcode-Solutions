#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the array to easily handle duplicates and use two pointers
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the current lowest number is > 0, 
            // no three numbers can sum up to 0.
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 2. Initialize two pointers for the remaining window
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Shift both pointers inward after finding a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Sum is too small; increase it by moving the left pointer rightward
                    left++;
                } 
                else {
                    // Sum is too large; decrease it by moving the right pointer leftward
                    right--;
                }
            }
        }
        
        return result;
    }
};
