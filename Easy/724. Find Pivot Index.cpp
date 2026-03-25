class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        int pivotSum = 0;
        for (int i = 0; i < n; i++) {
            int rightVal = total - pivotSum - nums[i];
            if (pivotSum == rightVal) return i;
            pivotSum += nums[i];
        }
        return -1;
    }
};

// find total , if right is squal to left return i 
// if not till end return -1