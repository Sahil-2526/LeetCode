class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]+=grid[i-1][j];
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=0;j<m;j++){
                val+=grid[i][j];
                if(val<=k) count++;
            }
        }

        return count;
    }
};

// first we will fill the matrix with sum of column ( while find all possible value of column containing top row value )
// then for each row we will start summing from left to right and check value ( ensure rightmost is present )
// if sum <=k then count increase 