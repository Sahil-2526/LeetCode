#include<vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int l = start, r = start;

        while (l >= 0 || r < n) {
            if (l >= 0 && nums[l] == target) 
                return start - l;

            if (r < n && nums[r] == target) 
                return r - start;

            l--;
            r++;
        }
        return 0;
    }
};