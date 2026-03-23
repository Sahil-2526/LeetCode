class Solution {
public:
    vector<vector<long long>> minDP = vector<vector<long long>>(15, vector<long long>(15, LLONG_MAX));
    vector<vector<long long>> maxDP = vector<vector<long long>>(15, vector<long long>(15, LLONG_MIN));

    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        const int MOD = 1e9 + 7;
        minDP[0][0] = maxDP[0][0] = grid[0][0];

        for (int j = 1; j < c; j++) {
            maxDP[0][j] = maxDP[0][j-1] * grid[0][j];
            minDP[0][j] = maxDP[0][j];
        }

        for (int i = 1; i < r; i++) {
            maxDP[i][0] = maxDP[i-1][0] * grid[i][0];
            minDP[i][0] = maxDP[i][0];
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                long long val = grid[i][j];

                long long a = maxDP[i-1][j] * val;
                long long b = minDP[i-1][j] * val;
                long long c1 = maxDP[i][j-1] * val;
                long long d = minDP[i][j-1] * val;

                maxDP[i][j] = max({a, b, c1, d});
                minDP[i][j] = min({a, b, c1, d});
            }
        }

        long long res = maxDP[r-1][c-1];
        if (res < 0) return -1;
        return res % MOD;
    }
};

// We use two DP tables, minDP and maxDP, to store the minimum and maximum product paths to each cell.
// We initialize the first row and first column based on the values in the grid.
// For each cell, we calculate the product of the current cell value with the maximum and minimum
// values from the top and left cells, and update the maxDP and minDP accordingly.
// Finally, we check the value at the bottom-right cell. If it's negative, we return -1, otherwise we return the value modulo 1e9 + 7.