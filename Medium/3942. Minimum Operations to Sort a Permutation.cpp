class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(2*n);
        for(int i=0; i<2*n; i++)
            arr[i] = i%n;

        vector<int> rev = arr;
        reverse(rev.begin(), rev.end());

        int strt = nums[0];
        int end = nums[n-1];
        int res = -1;

        if(vector<int>(arr.begin()+strt, arr.begin()+strt+n) == nums){
            res = min((n-strt)%n, end+3);
        }

        if(vector<int>(rev.begin()+n-strt-1, rev.begin()+2*n-strt-1) == nums){
            int x = min((strt+1)%n, (n-end)%n) + 1;
            if(res == -1) res = x;
            else res = min(res, x);
        }

        return res;
    }
};