class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {

                vector<int> arr;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        arr.push_back(grid[x][y]);
                    }
                }

                sort(arr.begin(), arr.end());

                int res = INT_MAX;

                for (int t = 1; t < arr.size(); t++) {
                    int diff = arr[t] - arr[t - 1];
                    if (diff > 0) {
                        res = min(res, diff);
                    }
                }

                if (res == INT_MAX) res = 0;

                ans[i][j] = res;
            }
        }

        return ans;
    }
};

//first we loop over all possible submatrices of size k*k and store elements
// we sort all the elements
// we find minimum difference
// we store it in array and return the array at the end


//  -----------------------------------------------------------------------------------------------

// class Solution {
// public:
//     vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
//         int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

//         for (int i = 0; i <= n - k; i++) {
//             for (int j = 0; j <= m - k; j++) {

//                 vector<int> arr;

//                 for (int x = i; x < i + k; x++) {
//                     for (int y = j; y < j + k; y++) {
//                         arr.push_back(grid[x][y]);
//                     }
//                 }

//                 sort(arr.begin(), arr.end());

//                 int res = INT_MAX;

//                 for (int t = 1; t < arr.size(); t++) {
//                     int diff = arr[t] - arr[t - 1];
//                     if (diff > 0) {
//                         res = min(res, diff);
//                     }
//                 }

//                 if (res == INT_MAX) res = 0;

//                 ans[i][j] = res;
//             }
//         }

//         return ans;
//     }
// };