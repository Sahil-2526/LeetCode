class Solution {
public:
    void swap(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = 0; i < k / 2; i++) {
            for(int j = 0; j < k; j++) {
                swap(grid[x+i][y+j], grid[x+k-1-i][y+j]);
            }
        }
        return grid;
    }
};

// we loop over the first half of the submatrix and swap the elements with the corresponding elements in the second half of the submatrix
// we return the modified grid at the end