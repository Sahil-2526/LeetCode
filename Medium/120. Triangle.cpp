class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int mn = INT_MAX;
                if (i > 0 && j > 0)
                    mn = min(mn, dp[i-1][j-1]);
                if (i > 0 && j < i)
                    mn = min(mn, dp[i-1][j]);
                dp[i][j] = (mn == INT_MAX)
                             ? triangle[i][j]
                             : mn + triangle[i][j];
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].begin() + n);
    }
};