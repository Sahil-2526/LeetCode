class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        multiset<int> minK;
        dp[0] = nums[0];
        minK.insert(dp[0]);
        for (int i = 1; i < n; i++) {
            dp[i] = *minK.rbegin() + nums[i];
            minK.insert(dp[i]);
            if (i >= k) {
                auto it = minK.find(dp[i - k]);
                minK.erase(it);
            }
        }
        return dp[n - 1];
    }
};