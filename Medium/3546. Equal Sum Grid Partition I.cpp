class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;

        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }

        if (total % 2 != 0) return false;

        long long target = total / 2;

        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        sum = 0;
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }

        return false;
    }
};

// first we check total even or odd , odd -> can't be equally divided into 2 parts
// if even , find target = total / 2
// then we check row wise and column wise sum , if any of them is equal to target
// then we can partition the grid into 2 equal sum parts by that row or column