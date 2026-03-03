class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    a[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    a[i][j]=1;
                    continue;
                }
                if(i==0){
                    a[i][j]=a[i][j-1];
                    continue;
                }
                if(j==0){
                    a[i][j]=a[i-1][j];
                    continue;
                }
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        return a[m-1][n-1];
    }
};