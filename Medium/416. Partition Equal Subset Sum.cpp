class Solution {
public:
    bool solve(int i, int val, int target, vector<vector<int>>& dp, vector<int>& nums) {
        if (val == target) return true;
        if (i == nums.size() || val > target) return false;
        if (dp[i][val] != -1) return dp[i][val];
        bool ok = solve(i+1, val+nums[i], target, dp, nums);
        bool nok = solve(i+1, val, target, dp, nums);
        return dp[i][val] = ok || nok;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums){
            sum += x;
        }
        if (sum % 2) return false;
        int n = nums.size();
        int aim = sum/2;
        vector<vector<int>> dp(n, vector<int>(aim, -1));
        return solve(0, 0, aim, dp, nums);
    }
};