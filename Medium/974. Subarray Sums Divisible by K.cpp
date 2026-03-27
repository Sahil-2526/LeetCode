class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> pfs(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pfs[i] = pfs[i - 1] + nums[i - 1];
        }

        for (int i = 0; i <= n; i++) {
            pfs[i] = ((pfs[i] % k) + k) % k;
        }

        unordered_map<int, int> freq;

        for (int i = 0; i <= n; i++) {
            freq[pfs[i]]++;
        }

        int count = 0;

        for (auto it : freq) {
            int f = it.second;
            count += (f * (f - 1)) / 2;
        }

        return count;
    }
};