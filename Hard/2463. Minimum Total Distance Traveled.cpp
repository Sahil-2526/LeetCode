class Solution {
public:
    long long dp[101][10001];

    long long solve(vector<int>& robot, vector<int>& factories, int r, int f) {
        if (r >= robot.size()) return 0;
        if (f >= factories.size()) return 1e18;

        if (dp[r][f] != -1) return dp[r][f];

        long long take = abs(robot[r] - factories[f]) + solve(robot, factories, r+1, f+1);
        long long skip = solve(robot, factories, r, f+1);

        return dp[r][f] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factories;

        for (auto &f : factory) {
            factories.insert(factories.end(), f[1], f[0]);
        }

        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());

        memset(dp, -1, sizeof(dp));

        return solve(robot, factories, 0, 0);
    }
};