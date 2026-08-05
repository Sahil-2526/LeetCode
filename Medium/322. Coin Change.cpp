class Solution {
public:
    // Initializing dp
    vector<int> dp;
    
    // function to find minimum number of coins at particular amoount value
    int findCoins(int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;

        for (int coin : coins) {
            int res = findCoins(amount - coin, coins);
            if (res != INT_MAX) ans = min(ans, res + 1);
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        // Declaring dp
        dp.resize(amount + 1, -1);
        
        // calling findCoins function
        int ans = findCoins(amount, coins);

        return (ans == INT_MAX) ? -1 : ans;
    }
};