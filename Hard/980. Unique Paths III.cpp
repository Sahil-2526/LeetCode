class Solution {
public:
    int rows, cols;
    int totalWalkable = 0;
    int answer = 0;
    void dfs(int x, int y, int count,vector<vector<int>>& grid,vector<vector<int>>& visited) {
        if (grid[x][y] == 2) {
            if (count == totalWalkable) {
                answer++;
            }
            return;
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (grid[nx][ny] != -1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    dfs(nx, ny, count + 1, grid, visited);
                    visited[nx][ny] = 0; 
                }
            }
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {    
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int startX = 0, startY = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != -1) {
                    totalWalkable++;
                }
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        visited[startX][startY] = 1;
        dfs(startX, startY, 1, grid, visited);   
        return answer;
    }
};