class Solution {
public:
    vector<int> dp;
    int n;

    int solve(int i, vector<int>& nums, int target) {
        if (i == n - 1) return 0;

        if (dp[i] != -2) return dp[i];

        int maxJumps = -1;

        for (int j = i + 1; j < n; j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                int next = solve(j, nums, target);

                if (next != -1) {
                    maxJumps = max(maxJumps, 1 + next);
                }
            }
        }

        return dp[i] = maxJumps;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(n, -2);

        return solve(0, nums, target);
    }
};