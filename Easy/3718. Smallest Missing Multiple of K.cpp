class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bitset<100> b;
        for (int x : nums) {
            if (x % k == 0) b.set(x / k - 1);
        }
        for (int i = 0; i < 100; i++) {
            if (!b[i]) return (i + 1) * k;
        }
        return 100+(k - 100%k);
    }
};