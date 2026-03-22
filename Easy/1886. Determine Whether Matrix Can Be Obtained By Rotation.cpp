class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bool zero = true, one = true, two = true, three = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] != target[i][j]) zero = false;
                if(mat[i][j] != target[j][n-i-1]) one = false;
                if(mat[i][j] != target[n-i-1][n-j-1]) two = false;
                if(mat[i][j] != target[n-j-1][i]) three = false;
            }
        }

        return zero||one||two||three;
    }
};

// check every element for every rotation and if any of the rotations match the target, we return true. If none of the rotations match, we return false at the end