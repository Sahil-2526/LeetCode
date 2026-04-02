#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();

        vector<int> result(n);
        int strt=0,lst=n-1;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                result[strt]=nums[i];
                strt++;
            }
            else{
                result[lst]=nums[i];
                lst--;
            }
        }
        
        return result;
    }
};