#include <cmath>
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD=1e9 + 7;
        long long ans=0;
        for (int i=1;i<=n;i++) {
            int bits=floor(log2(i))+1;  
            ans=((ans<<bits)%MOD+i)%MOD;
        }
        return ans;
    }
};