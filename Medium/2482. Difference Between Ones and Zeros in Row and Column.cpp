class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> row(2, vector<int>(m, 0)); 
        vector<vector<int>> col(2, vector<int>(n, 0)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[1][i]++;
                    col[1][j]++;
                }
                else{
                    row[0][i]++;
                    col[0][j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=row[1][i]-row[0][i]+col[1][j]-col[0][j];
            }
        }
        return grid;
    }
};