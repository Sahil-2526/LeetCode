class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int max_good_len = 0;

        unordered_map<int, int> freq;

        for(int j=0; j<nums.size(); j++) {
            freq[nums[j]]++;
            while (freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }
            max_good_len = max(max_good_len, j - i + 1);
        }
        return max_good_len;
    }
};