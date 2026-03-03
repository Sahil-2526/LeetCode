class Solution(object):
    def nextGreatestLetter(self, letters, target):
        n=float('inf')
        for a in letters:
            if ord(a) > ord(target) and ord(a) < n:
                n=ord(a)
        if n == float('inf'):
            n=ord(letters[0])
        return chr(n)
        