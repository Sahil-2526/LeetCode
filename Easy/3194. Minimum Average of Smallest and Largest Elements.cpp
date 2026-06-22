class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double res = DBL_MAX;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            res = min( res, (nums[i]+nums[j]) /2.0);
            i++;
            j--;
        }

        return res;
    }
};