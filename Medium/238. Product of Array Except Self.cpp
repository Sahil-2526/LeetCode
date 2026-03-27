#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();

        int total=1;
        int zeroExist=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zeroExist++;
            else total*=nums[i];
        }

        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            if(zeroExist>1) break;
            if(zeroExist==1 && nums[i]==0) result[i]=total;
            if(zeroExist==0) result[i]=total/nums[i];
        }

        return result;
    }
};