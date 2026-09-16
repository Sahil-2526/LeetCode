class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<ll>> dp(n, vector<ll>(k+1, 0));

        for(int i = 1; i < n; i++)
            dp[i][1] = 1LL * i * (i + 1) / 2 % MOD;

        for(int j = 2; j <= k; j++) {
            ll sum = 0;
            ll weighted = 0;

            for(int i = 1; i < n; i++) {
                sum = (sum + dp[i][j-1]) % MOD;
                weighted = (weighted + 1LL * i * dp[i][j-1]) % MOD;

                dp[i][j] = (1LL * i * sum - weighted) % MOD;

                if(dp[i][j] < 0)
                    dp[i][j] += MOD;
            }
        }

        return dp[n-1][k];
    }
};