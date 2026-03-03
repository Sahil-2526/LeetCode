class Solution {
public:
    void swap(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
        int zero_idx=0;
        int two_idx=nums.size()-1;
        while(nums[zero_idx]==0 && zero_idx<nums.size()-1) zero_idx++;
        while(nums[two_idx]==2 && two_idx>0) two_idx--;
        if(nums.size()>1 && zero_idx!=nums.size()-1 && two_idx!=0){
        for(int i=zero_idx;i < nums.size() && i <= two_idx;i++){
            if(i<zero_idx) continue;
            if(nums[i]==2){
                swap(nums[i],nums[two_idx]);
                two_idx--;
                while(nums[two_idx]==2 && two_idx>0) two_idx--;
            }
            if(nums[i]==0){
                swap(nums[i],nums[zero_idx]);
                zero_idx++;
                while(nums[zero_idx]==0 && zero_idx<nums.size()-1) zero_idx++;
            }
        } }
    }
};