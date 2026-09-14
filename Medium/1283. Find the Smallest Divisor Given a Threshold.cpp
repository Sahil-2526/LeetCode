class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l=1, r=*max_element(nums.begin(), nums.end());
        int res = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            int count = 0;
            for(int i=0; i<n; i++){
                count += ((nums[i]+mid-1)/mid);
            }
            if(count <= threshold){
                res = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};