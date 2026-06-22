class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            st.insert(nums[i] + nums[j]);
            i++;
            j--;
        }
        return st.size();
    }
};