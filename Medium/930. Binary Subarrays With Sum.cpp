class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pfs(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pfs[i] = pfs[i - 1] + nums[i - 1];
        }

        int count = 0;

        for (int right = 1; right <= n; right++) {
            for (int left = 0; left < right; left++) {
                if (pfs[right] - pfs[left] == goal) {
                    count++;
                }
            }
        }

        return count;
    }
};