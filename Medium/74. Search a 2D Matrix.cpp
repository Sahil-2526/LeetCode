class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0, r=n*m-1; 
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[mid/m][mid%m] > target)
                r = mid-1;
            else if(matrix[mid/m][mid%m] < target)
                l = mid+1;
            else
                return true;    
        }
        return false;
    }
};