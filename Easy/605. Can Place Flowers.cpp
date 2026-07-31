class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int count = 0;
        int zeros = 0;

        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) zeros++;
            else {
                if (i == zeros) count += zeros / 2;
                else count += max(0, (zeros - 1) / 2);
                zeros = 0;
            }
        }
        if (zeros > 0) {
            if (zeros == m) count += (zeros + 1) / 2;
            else count += zeros / 2;
        }
        return count >= n;
    }
};