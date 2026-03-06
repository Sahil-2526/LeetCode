class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=nums.size();
        int ones=0;
        int count=0;
        for(int i=0;i<len;i++){
            if(nums[i]==1) count++;
            if(i==len-1){
                if(nums[i]==1) ones=max(ones,count);
            }
            else if(nums[i]==1 && nums[i+1]==0){
                ones=max(ones,count);
                count=0;
            }
        }
        return ones;
    }
};