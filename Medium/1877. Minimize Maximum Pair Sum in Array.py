class Solution(object):
    def minPairSum(self, nums):
        nums.sort()
        l=len(nums)
        arr=[]
        for i in range(0,l/2):
            arr.append(nums[i]+nums[l-i-1])        
        return max(arr)