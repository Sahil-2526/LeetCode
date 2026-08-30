class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n+1, 0);

        for (int i=0; i<n; i++) {
            ps[i+1] = ps[i] + (nums[i]%2);
        }

        unordered_map<int, int> freq;
        freq[0] = 1;

        int count = 0;

        for (int r = 1; r <= n; r++) {
            int need = ps[r]-k;
            if (freq.count(need)) {
                count += freq[need];
            }
            freq[ps[r]]++;
        }

        return count;
    }
};