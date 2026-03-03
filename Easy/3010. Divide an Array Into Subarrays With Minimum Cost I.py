class Solution(object):
    def minimumCost(self, nums):
        count=nums[0]
        arr=sorted(nums[1:])
        k=0
        count=count+arr[0]+arr[1]
        return count