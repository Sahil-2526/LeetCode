class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {

                if(grid[i][j] != 0)
                    continue;

                queue<pair<int,int>> q;
                q.push({i, j});
                grid[i][j] = 1;

                bool flag = true;

                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    int dx[] = {1, -1, 0, 0};
                    int dy[] = {0, 0, 1, -1};

                    for(int k = 0; k < 4; k++) {
                        int a = x + dx[k];
                        int b = y + dy[k];

                        if(a < 0 || a >= n || b < 0 || b >= m) {
                            flag = false;
                        }
                        else if(grid[a][b] == 0) {
                            grid[a][b] = 1;
                            q.push({a, b});
                        }
                    }
                }

                if(flag)
                    res++;
            }
        }

        return res;
    }
};