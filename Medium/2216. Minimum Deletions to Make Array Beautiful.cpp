class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int len = nums.size();
        int remove = 0;
        for (int i = 0; i < len - 1; i++) {
            if ((i - remove) % 2 == 0 && nums[i] == nums[i + 1]) {
                remove++; 
            }
        }
        if ((len - remove) % 2 != 0) remove++;
        return remove;
    }
};