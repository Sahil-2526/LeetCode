import math

class Solution(object):
    def reverseBits(self, n):
        product = 0
        for i in range(32):
            k = int(math.log(n,2)) if n > 0 else 0
            product += 2 ** (31 - k) if n > 0 else 0
            n -= 2 ** k if n > 0 else 0
        return product


# in cpp

# class Solution {
# public:
#     int reverseBits(int n) {
#         int mx= INT_MAX;
#         int val=0;
#         for(int i=0;i<32;i++){
#             if(n%2!=0) val+=(int)pow(2,31-i)%mx;
#             n=n>>1;
#         }
#         return val%mx;
#     }
# };