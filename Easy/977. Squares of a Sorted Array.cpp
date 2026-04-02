#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int l = 0, r = n - 1;
        int pos = n - 1;

        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                result[pos--] = nums[l] * nums[l];
                l++;
            } else {
                result[pos--] = nums[r] * nums[r];
                r--;
            }
        }

        return result;
    }
};