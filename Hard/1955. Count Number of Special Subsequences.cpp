class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long power(long long exp) {
        long long result = 1;
        long long base = 2;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevZero(n, 0);
        int zero = 0, two = 0;
        long long res = 0, val = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                prevZero[i] = zero;
                zero++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 2) two++;
            if (nums[i] == 1) val = ( (2LL * val) % MOD + power(two) - 1 + MOD ) % MOD;
            if (nums[i] == 0) res = ( res + (power(prevZero[i]) * val) % MOD ) % MOD;
        }
        return (int)(res % MOD);
    }
};