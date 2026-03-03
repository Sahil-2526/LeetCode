class Solution {
public:
    char findKthBit(int n, int k) {
        int inv = 0;
        while(n>1) {
            int len=(1<<n)-1;      // 2^n-1
            int mid=(len/2)+1;
            if (k==1) break;
            if (k == mid) return (inv % 2 == 0) ? '1' : '0';
            if (k > mid) {
                k=len-k+1;
                inv++;
            }
            n--;
        }
        return (inv % 2 == 0) ? '0' : '1';
    }
};

