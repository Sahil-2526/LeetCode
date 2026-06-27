class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums){
            freq[x]++;
        }
        int ans = 1;
        if (freq.count(1) > 0) {
            if (freq[1] % 2 == 1)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }
        for (auto &[num, cnt] : freq) {
            if (num == 1) continue;
            long long x = num;
            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {
                len += 2;
                x = x * x;
            }
            if (freq.count(x) && freq[x] == 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};