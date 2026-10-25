class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        long long res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > maxK || nums[i] < minK){
                res += count*(count+1)/2;
                count = 0;
            }
            else{
                count++;
            }
        }
        res += count*(count+1)/2;
        return res;
    }
};