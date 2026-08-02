class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int u=0;
                int l=0;
                if(i>0) u = dp[i-1][j];
                if(j>0) l = dp[i][j-1];
                if(i>0 && j>0) dp[i][j] = min(u,l)+grid[i][j];
                else dp[i][j] = max(u,l)+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};