class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n, vector<int>(m));

        k %= (n * m);

        for (int i = 0; i < n * m; i++) {
            int idx = (i + k) % (n * m);

            res[idx / m][idx % m] = grid[i / m][i % m];
        }

        return res;
    }
};