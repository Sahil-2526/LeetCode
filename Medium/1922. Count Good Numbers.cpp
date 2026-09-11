class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long e = (n + 1) / 2;
        long long o = n / 2;

        return (power(5, e) * power(4, o)) % MOD;
    }
};