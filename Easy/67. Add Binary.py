class Solution(object):
    def addBinary(self, a, b): 
        max_len = max(len(a), len(b))
        a = a.zfill(max_len)
        b = b.zfill(max_len)
        carry = 0
        result = ""
        for i in range(max_len - 1, -1, -1):
            total = int(a[i]) + int(b[i]) + carry
            result = str(total % 2) + result
            carry = total // 2
        if carry:
            result = "1" + result

        return result