#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));

        for (int j = 1; j <= k; j++) {
            dp[j][1] = - (long long)prices[0];
            dp[j][2] = prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp[j][0] = max({
                    dp[j][0],
                    dp[j][1] + (long long)prices[i],
                    dp[j][2] - (long long)prices[i]
                });

                dp[j][1] = max(
                    dp[j][1],
                    dp[j-1][0] - (long long)prices[i]
                );

                dp[j][2] = max(
                    dp[j][2],
                    dp[j-1][0] + (long long)prices[i]
                );
            }
        }

        return dp[k][0];
    }
};