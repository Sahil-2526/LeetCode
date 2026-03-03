import math

class Solution(object):
    def reverseBits(self, n):
        product = 0
        for i in range(32):
            k = int(math.log(n,2)) if n > 0 else 0
            product += 2 ** (31 - k) if n > 0 else 0
            n -= 2 ** k if n > 0 else 0
        return product