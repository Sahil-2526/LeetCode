class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int init=0;
        int k=1;
        for(int i=1;i<n;i++){
            if(nums[init]==nums[i]) continue;
            else{
                nums[k]=nums[i];
                k++;
                init=i;
                count++;
            }
        }
        return count;
    }
};