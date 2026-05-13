class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int l = nums[i], r = nums[n - i - 1];
            int low = 1 + min(l, r);
            int high = limit + max(l, r);
            int s  = l + r;
            diff[2]+=2;
            diff[2*limit+1]-=2;
            diff[low]-=1;
            diff[high+1]+= 1;
            diff[s]-= 1;
            diff[s+1]+= 1;
        }

        int ans = INT_MAX, cur = 0;
        for (int t = 2; t <= 2 * limit; t++) {
            cur += diff[t];
            ans = min(ans, cur);
        }
        return ans;
    }
};