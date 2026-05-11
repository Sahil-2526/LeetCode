class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                result.push_back(0);
                continue;
            }
            vector<int> r;
            while(nums[i]!=0){
                r.push_back(nums[i]%10);
                nums[i]/=10;
            }
            for(int j=r.size()-1;j>=0;j--){
                result.push_back(r[j]);
            }
        }
        return result;
    }
};