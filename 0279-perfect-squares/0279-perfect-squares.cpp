#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int numSquares(int n) {
        // Create a DP vector initialized with a worst-case value (n)
        std::vector<int> dp(n + 1, n);
        
        // Base case: 0 requires 0 perfect squares
        dp[0] = 0;
        
        // Build up the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
    }
};
