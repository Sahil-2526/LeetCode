class Solution(object):
    def repeatedNTimes(self, nums):
        done=set()
        for i in nums:
            if i in done:
                return i
            else :
                done.add(i)