class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            int rev = reverse(nums[i]);
            if (mp.find(nums[i]) != mp.end()) {
                minDist = min(minDist, i - mp[nums[i]]);
            }
            mp[rev] = i;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};