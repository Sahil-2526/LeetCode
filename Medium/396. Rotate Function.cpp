class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long fn=0;
        for(int i=0;i<n;i++){
            sum+=(long long)nums[i];
            fn+=(long long)nums[i]*(long long)i;
        }
        long long res=LLONG_MIN;
        for(int i=0;i<n;i++){
            res=max(res,fn);
            fn=fn+sum-(long long)(n*nums[n-i-1]);
        }
        return res;
    }
};