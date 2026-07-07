class Solution {
public:
    long long sumAndMultiply(int n) {
        long long MOD = LLONG_MAX;
        long long res = 0;
        long long multiplier = 1;
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                sum += digit;
                res += digit * multiplier;
                multiplier *= 10;
            }
            n /= 10;
        }
        return (res*sum) % MOD;
    }
};