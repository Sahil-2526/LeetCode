class NumArray {
    vector<long long> prefixSum;
    const long long MOD = 1e9 + 7;

public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        prefixSum.assign(len + 1, 0);

        for (int i = 1; i <= len; i++) {
            prefixSum[i] = (prefixSum[i - 1] + nums[i - 1]) % MOD;
        }
    }
    
    long long sumRange(int left, int right) {
        long long result = (prefixSum[right + 1] - prefixSum[left]) % MOD;
        
        return result;
    }
};