class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pfs(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pfs[i] = pfs[i - 1] + nums[i - 1];
        }

        int count = 0;

        for (int right = 1; right <= n; right++) {
            for (int left = 0; left < right; left++) {
                if (pfs[right] - pfs[left] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};