class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> best(n, vector<int>(m, -1));
        int newH = health - grid[0][0];
        if (newH <= 0) return false;
        queue<tuple<int,int,int>> q;
        q.push({0, 0, newH});
        best[0][0] = newH;
        while (!q.empty()) {
            auto [i, j, h] = q.front();
            q.pop();
            if (i == n - 1 && j == m - 1) return true;
            for (auto [dx, dy] : dir) {
                int ni = i + dx;
                int nj = j + dy;
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                int newH = h - grid[ni][nj];
                if (newH <= 0) continue;
                if (newH > best[ni][nj]) {
                    best[ni][nj] = newH;
                    q.push({ni, nj, newH});
                }
            }
        }
        return false;
    }
};