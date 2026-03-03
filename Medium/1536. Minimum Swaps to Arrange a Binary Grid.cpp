class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> z;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            z.push_back(count);
        }
        int swaps=0;
        for(int i=0;i<n;i++) {
            int num=n-i-1;
            int j=i;
            while(j<n && z[j]<num) {
                j++;
            }
            if(j == n) return -1;
            while(j > i) {
                swap(z[j],z[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};