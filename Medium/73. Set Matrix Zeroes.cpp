class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> row(r,1);
        vector<int> col(c,1);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(row[i]==0 || col[j]==0) matrix[i][j]=0;
            }
        }
    }
};


// tranverse through every element
// if value is 0 at index i,j -> make row[i] and col[j] = 0 , to store which row is and column in 0
// traverse through the matrix , if row[i] or col[j] is 0 make that row / column 0