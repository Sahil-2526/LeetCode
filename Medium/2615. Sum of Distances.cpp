class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }

        for (auto &x : indices) {
            vector<int> &a = x.second;
            int len = a.size();

            vector<long long> ps(len, 0);
            ps[0] = a[0];

            for (int i = 1; i < len; i++) {
                ps[i] = ps[i - 1] + a[i];
            }

            for (int i = 0; i < len; i++) {
                long long left = (long long)a[i] * i - (i > 0 ? ps[i - 1] : 0);
                long long right = (ps[len - 1] - ps[i]) - (long long)a[i] * (len - i - 1);

                result[a[i]] = left + right;
            }
        }

        return result;
    }
};