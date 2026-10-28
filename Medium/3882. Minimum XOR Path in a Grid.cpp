class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> cur(m, vector<bool>(1024, false));
        vector<vector<bool>> next(m, vector<bool>(1024, false));

        for(int i = 0; i < n; i++){
            next = vector<vector<bool>>(m, vector<bool>(1024, false));

            for(int j = 0; j < m; j++){
                for(int k = 0; k < 1024; k++){
                    if(i == 0) next[0][grid[0][0]] = true;
                    int val = k ^ grid[i][j];

                    if(i > 0 && cur[j][val])
                        next[j][k] = true;

                    if(j > 0 && next[j-1][val])
                        next[j][k] = true;
                }
            }

            cur = next;
        }

        for(int i = 0; i < 1024; i++){
            if(cur[m-1][i]) return i;
        }

        return -1;
    }
};