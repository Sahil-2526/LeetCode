class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0;
        int mx2 = 0;
        int n = nums.size();
        for(int x : nums){
            if(x>mx2){
                mx1 = mx2;
                mx2 = x;
            }
            else if(x> mx1){
                mx1 = x;
            }
        }
        return (mx1-1)*(mx2-1);
    }
};