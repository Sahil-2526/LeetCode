class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        vector<int> prefixSum(len, 0);
        prefixSum[0] = nums[0] % k;

        for (int i = 1; i < len; i++) {
            prefixSum[i] = (prefixSum[i - 1] + nums[i]) % k;
        }

        unordered_set<int> findDup;
        findDup.insert(0);

        for (int i = 1; i < len; i++) {
            if (findDup.find(prefixSum[i]) != findDup.end()) {
                return true;
            }
            findDup.insert(prefixSum[i - 1]);
        }

        return false;
    }
};