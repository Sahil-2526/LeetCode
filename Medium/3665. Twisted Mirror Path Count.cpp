class Solution {
public:
    typedef pair<int, int> pii;

    struct Hash {
        size_t operator()(const pii& p) const {
            return p.first * 100000 + p.second;
        }
    };

    long long uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long MOD = 1e9 + 7;

        vector<vector<long long>> res(n, vector<long long>(m, 0));
        unordered_map<pii, pair<long long, long long>, Hash> mp;
        // l, u

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    res[0][0] = 1;
                    continue;
                }

                long long l = 0, u = 0;

                if(i > 0){
                    if(grid[i-1][j] == 0)
                        u = res[i-1][j];
                    else{
                        if(j > 0)
                            u = mp[{i-1,j}].first;
                    }
                }

                if(j > 0){
                    if(grid[i][j-1] == 0)
                        l = res[i][j-1];
                    else{
                        if(i > 0)
                            l = mp[{i,j-1}].second;
                    }
                }

                if(grid[i][j] == 1){
                    mp[{i,j}] = {l % MOD, u % MOD};
                }
                else{
                    res[i][j] = (l + u) % MOD;
                }
            }
        }

        return res[n-1][m-1];
    }
};