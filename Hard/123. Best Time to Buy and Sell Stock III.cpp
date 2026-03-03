#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int k=2;
        vector<vector<int>> dp(k + 1, vector<int>(3, 0));
        for (int j = 1; j <= k; j++) {
            dp[j][1] = -prices[0]; 
        }

        for (int i = 1; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp[j][0] = max({
                    dp[j][0],                  
                    dp[j][1] + prices[i]
                });
                dp[j][1] = max(
                    dp[j][1],                  
                    dp[j-1][0] - prices[i]     );
            }
        }

        return dp[k][0]; 
    }
}; 