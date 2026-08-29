class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int last = 0;
        int mx = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                if(k != 0) k--;
                else{
                    while(nums[last] != 0) last++;
                    last++;
                }
            }
            if(k>=0) mx = max(mx, i-last+1);
        }
        return mx;
    }
};