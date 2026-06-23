class Solution {
public:
    static const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<long long>> next(m, vector<long long>(2, 1));
        vector<vector<long long>> cur(m, vector<long long>(2));
        for (int pos = n - 2; pos >= 0; pos--) {
            vector<long long> preGreater(m), sufLess(m);
            preGreater[0] = next[0][1];
            for (int i = 1; i < m; i++) {
                preGreater[i] = (preGreater[i - 1] + next[i][1]) % MOD;
            }
            sufLess[m - 1] = next[m - 1][0];
            for (int i = m - 2; i >= 0; i--) {
                sufLess[i] = (sufLess[i + 1] + next[i][0]) % MOD;
            }
            for (int v = 0; v < m; v++) {
                cur[v][0] = (v > 0 ? preGreater[v - 1] : 0);
                cur[v][1] = (v + 1 < m ? sufLess[v + 1] : 0);
            }
            swap(cur, next);
        }
        long long ans = 0;
        for (int v = 0; v < m; v++) {
            ans = (ans + next[v][0]) % MOD;
            ans = (ans + next[v][1]) % MOD;
        }
        return ans;
    }
};