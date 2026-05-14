class Solution {
public:
    bool isGood(vector<int>& nums) {
        bitset<199> arr;
        int last=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>n-1) return false;
            else if(nums[i]<n-1){
                if(arr[nums[i]-1]==0) arr.set(nums[i]-1);
                else return false;
            }
            else{
                if(last>1) return false;
                else last++;
            }
        }
        return true;
    }
};