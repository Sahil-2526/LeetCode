class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(l==r-1) return min(nums[l],nums[r]);
            if(nums[mid]>nums[r]) l=mid;
            else r=mid;
        }
        return min(nums[l],nums[r]);
    }
};