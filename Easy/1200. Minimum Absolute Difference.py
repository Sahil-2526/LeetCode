class Solution(object):
    def minimumAbsDifference(self, arr):
        arr.sort()
        a=[]
        k=arr[1]-arr[0]
        for i in range(1,len(arr)-1):
            if k>arr[i+1]-arr[i]:
                k=arr[i+1]-arr[i]
        for i in range(0,len(arr)-1):
            if arr[i+1]-arr[i] == k :
                a.append([arr[i],arr[i+1]])
        return a