class Solution {
public:
    // Initializing dp
    vector<vector<int>> dp;

    int sum_arr = 0;

    // Function that stores number of ways from that point to get target
    int findWays(int target, int idx, vector<int>& nums){

        if(target < -sum_arr || target > sum_arr) return 0;

        if(idx == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }

        if(dp[idx][target + sum_arr] != -1)
            return dp[idx][target + sum_arr];

        int res = findWays(target - nums[idx], idx + 1, nums)
                + findWays(target + nums[idx], idx + 1, nums);

        return dp[idx][target + sum_arr] = res;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        for(int x : nums){
            sum_arr += x;
        }

        if(abs(target) > sum_arr) return 0;

        // Resizing dp
        dp.resize(n, vector<int>(2*sum_arr+1, -1));

        // Calling findWays function
        int res = findWays(target, 0, nums);

        return res;
    }
};