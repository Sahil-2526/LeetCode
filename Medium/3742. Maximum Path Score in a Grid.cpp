class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp_tp(m, vector<int>(k+1, -1));
        dp_tp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            vector<vector<int>> dp_l(m, vector<int>(k+1, -1));

            for (int j = 0; j < m; j++) {
                int val = grid[i][j];
                int cost = (val == 0 ? 0 : 1);

                for (int c = 0; c <= k; c++) {
                    if (c < cost) continue;

                    int prev = -1;

                    if (i > 0 && dp_tp[j][c - cost] != -1)
                        prev = dp_tp[j][c - cost];

                    if (j > 0 && dp_l[j - 1][c - cost] != -1)
                        prev = max(prev, dp_l[j - 1][c - cost]);

                    if (i == 0 && j == 0 && c == 0)
                        prev = 0;

                    if (prev != -1)
                        dp_l[j][c] = max(dp_l[j][c], prev + val);
                }
            }

            dp_tp = move(dp_l);
        }

        int res = -1;
        for (int c = 0; c <= k; c++) {
            res = max(res, dp_tp[m - 1][c]);
        }

        return res;
    }
};