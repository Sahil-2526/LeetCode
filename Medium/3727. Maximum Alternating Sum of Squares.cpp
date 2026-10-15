class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        int n = nums.size();
        long long sub=0, add=0;
        int i=0;
        for(; i<n/2; i++){
            sub += 1LL*nums[i]*nums[i];
        }
        for(; i<n; i++){
            add += 1LL*nums[i]*nums[i];
        }
        return add-sub;
    }
};