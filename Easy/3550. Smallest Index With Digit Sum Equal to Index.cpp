class Solution {
public:
    int digitSum(int n){
        int ds = 0;
        while(n > 0){
            ds += n % 10;
            n /= 10;
        }
        return ds;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == digitSum(nums[i])) return i;
        }
        return -1;
    }
};