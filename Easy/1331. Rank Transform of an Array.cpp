class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if( n == 0) return {};
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        vector<int> res(n);
        int rank = 1;
        res[nums[0]] = rank;
        for (int i = 1; i < n; i++) {
            if (arr[nums[i]] != arr[nums[i - 1]]) rank++;
            res[nums[i]] = rank;
        }
        return res;
    }
};