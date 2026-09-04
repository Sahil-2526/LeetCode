class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(n);

        long long mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, 1LL * nums[i]);
            res[i] = mx;
        }

        long long mn = nums[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, 1LL * nums[i]);
            res[i] -= mn;
        }

        for (int i = 0; i < n; i++) {
            if (res[i] <= k)
                return i;
        }

        return -1;
    }
};