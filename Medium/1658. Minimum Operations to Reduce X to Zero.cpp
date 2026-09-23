class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> st(n + 1);
        int count = 0;
        st[0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            count += nums[i];
            st[n - i] = count;
        }

        count = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int rem = x - count;

            auto it = lower_bound(st.begin(), st.end(), rem);

            if (it != st.end() && *it == rem) {
                int right = it - st.begin();

                if (i + right <= n)
                    ans = min(ans, i + right);
            }

            count += nums[i];
        }

        if (st[n] == x)
            ans = min(ans, n);

        return ans == INT_MAX ? -1 : ans;
    }
};