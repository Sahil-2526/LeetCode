class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        int left = k % m;
        int right = (m - left) % m;

        for(int i = 0; i < n; i++){
            int k = (i % 2 == 0) ? left : right;

            for(int j = 0; j < m; j++){
                if(mat[i][j] != mat[i][(j + k) % m]){
                    return false;
                }
            }
        }

        return true;
    }
};