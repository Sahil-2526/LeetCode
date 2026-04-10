#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int n = nums.size();
        int l = 0;
        long long product = 1;
        int count = 0;

        for (int r = 0; r < n; r++) {
            product *= nums[r];

            while (product >= k) {
                product /= nums[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }
};