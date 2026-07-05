class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1}; 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || board[i][j] == 'S') continue;
                int best = -1;
                long long ways = 0;
                vector<pair<int, int>> prev = {{i+1, j},{i, j+1},{i+1, j+1}};
                for (auto [x, y] : prev) {
                    if (x >= n || y >= n) continue;
                    if (dp[x][y].first == -1) continue;
                    if (dp[x][y].first > best) {
                        best = dp[x][y].first;
                        ways = dp[x][y].second;
                    } 
                    else if (dp[x][y].first == best) {
                        ways = (ways + dp[x][y].second) % MOD;
                    }
                }
                if (best == -1) continue;
                int val = 0;
                if (isdigit(board[i][j])) val = board[i][j] - '0';
                dp[i][j] = {best + val, (int)(ways % MOD)};
            }
        }
        if (dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};