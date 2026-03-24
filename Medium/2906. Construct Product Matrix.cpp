class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> prefixP(n*m+1,1);
        vector<long long> suffixP(n*m+1,1); 

        for(int i = 1; i < n*m + 1; i++){
            int r1 = (i - 1) / m;
            int c1 = (i - 1) % m;
            prefixP[i] = (prefixP[i - 1] * grid[r1][c1]) % 12345;
        
            int r2 = (n*m - i) / m;
            int c2 = (n*m - i) % m; 
            suffixP[n*m - i] = (suffixP[n*m - i + 1] * grid[r2][c2]) % 12345;
        }

        vector<vector<int>> ans(n, vector<int>(m,1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int idx = i * m + j;
                ans[i][j] = (prefixP[idx] * suffixP[idx+1]) % 12345;
            }
        }

        return ans;
    }
};

// first we will find prefix product and suffix product of the grid in a single loop and then we will find the answer for each cell by multiplying prefix and suffix product of that cell.
// then we will mudulo the answer by 12345 ( as given on the question ) and return the answer.