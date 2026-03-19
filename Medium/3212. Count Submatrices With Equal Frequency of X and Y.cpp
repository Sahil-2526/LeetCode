class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> x(n, vector<int>(m, 0));
        vector<vector<int>> y(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    if(grid[i][j]=='X') x[i][j]+=1;
                    else if(grid[i][j]=='Y') y[i][j]+=1;
                }
                else{
                    if(grid[i][j]=='X') x[i][j]=x[i-1][j]+1;
                    else x[i][j]=x[i-1][j];

                    if(grid[i][j]=='Y') y[i][j]=y[i-1][j]+1;
                    else y[i][j]=y[i-1][j];
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            int xVal=0;
            int yVal=0;
            for(int j=0;j<m;j++){
                    xVal+=x[i][j];
                    yVal+=y[i][j];
                    if(xVal==yVal && xVal>0) count++;
            }
        }

        return count;

    }
};

//we first count no. of x and y above and including the current cell and store it in x and y 2d vector respectively
// then we will iterate over the grid and keep adding the value of x and y in a row 
// if at any point xVal and yVal are equal and greater than 0 then we will increase the count by 1 (condition of question satoisfied)