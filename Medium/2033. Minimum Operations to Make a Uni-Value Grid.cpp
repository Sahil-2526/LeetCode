class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto& row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }

        int k = arr[0] % x;
        for (int val : arr) {
            if (val % x != k) return -1;
        }

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];

        int operations = 0;
        for (int val : arr) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};