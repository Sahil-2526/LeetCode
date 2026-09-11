class Solution {
public:
    double myPow(double x, int n) {
        long long new_n = abs((long long)n);
        double res = x;
        double extra = 1;
        while(new_n > 0) {
            if(new_n % 2 != 0)
                extra *= res;

            res = res * res;
            new_n /= 2;
        }

        if(n < 0)
            return 1 / extra;

        return extra;
    }
};