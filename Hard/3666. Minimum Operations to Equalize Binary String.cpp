class Solution {
public:
    int minOperations(string s, int k) {
        long long z = 0;
        for (char c : s) if (c == '0') ++z;
        long long n = s.length();
        long long o = n - z;

        if (z == 0) return 0;

        for (long long i = 1; i <= n; ++i) {
            long long total_flips = i * k;
            if ((total_flips - z) % 2 != 0) continue;

            if (i % 2 != 0) {
                if (total_flips >= z && total_flips <= (z * i + o * (i - 1))) return (int)i;
            } else {
                if (total_flips >= z && total_flips <= (z * (i - 1) + o * i)) return (int)i;
            }
        }
        return -1;
    }
};