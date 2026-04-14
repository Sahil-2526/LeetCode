class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long long> count;
        for (int x : arr) count[x]++;

        vector<int> nums;
        for (auto &p : count) nums.push_back(p.first);
        sort(nums.begin(), nums.end());

        long long result = 0;
        int m = nums.size();
        const int MOD = 1e9 + 7;

        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                int a = nums[i], b = nums[j];
                int c = target - a - b;

                if (c < b || count.find(c) == count.end()) continue;

                if (a == b && b == c) {
                    result += count[a] * (count[a] - 1) * (count[a] - 2) / 6;
                }
                else if (a == b && b != c) {
                    result += (count[a] * (count[a] - 1) / 2) * count[c];
                }
                else if (a < b && b == c) {
                    result += count[a] * (count[b] * (count[b] - 1) / 2);
                }
                else if (a < b && b < c) {
                    result += count[a] * count[b] * count[c];
                }

                result %= MOD;  
            }
        }

        return result % MOD;
    }
};