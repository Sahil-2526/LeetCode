class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int solve(int i, int s1, int s2, vector<int>& nums){
        if(i == nums.size()) return (s1 == s2 && s1 != 0);
        if(dp[i][s1][s2] != -1) return dp[i][s1][s2];
        long long ans = 0;
        ans += solve(i + 1, gcd(s1, nums[i]), s2, nums);
        ans += solve(i + 1, s1, gcd(s2, nums[i]), nums);
        ans += solve(i + 1, s1, s2, nums);
        ans %= MOD;
        return dp[i][s1][s2] = ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        dp.assign(nums.size(),vector<vector<int>>(mx + 1,vector<int>(mx + 1, -1)));
        return solve(0, 0, 0, nums);
    }
};