class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long min = nums[n/2];
        if(n%2 == 0) min =(min+nums[(n-1)/2])/2; 
        long long res = 0;
        for(int i=0; i<n; i++) res += abs(nums[i]-min);
        return (int)res;
    }
};