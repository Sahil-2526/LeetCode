class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int val = nums[q];
            vector<int>& arr = pos[val];

            if (arr.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(arr.begin(), arr.end(), q);
            int idx = it - arr.begin();

            int prev = (idx == 0) ? arr.back() : arr[idx - 1];
            int next = (idx == arr.size() - 1) ? arr[0] : arr[idx + 1];

            int d1 = abs(q - prev);
            d1 = min(d1, n - d1);

            int d2 = abs(q - next);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};