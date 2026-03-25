class Solution {
public:
    const int MOD = INT_MAX;

    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixSum;

        prefixSum.push_back(nums[0] % MOD);

        for (int i = 1; i < len; i++) {
            int curr = (prefixSum.back() + nums[i]) % MOD;
            prefixSum.push_back(curr);
        }

        return prefixSum;
    }
};

// first insert 1st element
// then use prefix sum method and keep inserting value