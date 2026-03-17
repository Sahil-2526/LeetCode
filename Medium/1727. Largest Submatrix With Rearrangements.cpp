class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1) matrix[i][j]+=matrix[i-1][j];
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> r=matrix[i];
            sort(r.begin(),r.end(),greater<int>());
            for(int j=0;j<m;j++){
                ans=max(ans,r[j]*(j+1));
            }
        }
        return ans;
    }
};

// first we will fill the matrix with number of consecutive 1 in the column 
// then we will pich each row and sort it 
// then we will run a loop to find the area by multiplying value with index+1 ( as number of column )