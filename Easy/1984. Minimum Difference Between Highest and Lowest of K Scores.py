class Solution(object):
    def minimumDifference(self, nums, k):
        nums.sort()
        n = nums[k-1] - nums[0]
        i = k
        while i < len(nums):
            if n > nums[i] - nums[i-k+1]:
                n = nums[i] - nums[i-k+1]
            i=i+1
        return n
        