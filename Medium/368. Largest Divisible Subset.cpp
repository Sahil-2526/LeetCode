class Solution {
public:
    typedef long long ll;

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> div(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    div[i] = max(div[i], div[j] + 1);
                }
            }
        }

        int mx = 0;
        int last = 0;

        for (int i = 0; i < n; i++) {
            if (div[i] > mx) {
                mx = div[i];
                last = i;
            }
        }

        vector<int> res;
        res.push_back(nums[last]);

        for (int i = last - 1; i >= 0; i--) {
            if (nums[last] % nums[i] == 0 && div[i] == div[last] - 1) {
                res.push_back(nums[i]);
                last = i;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};