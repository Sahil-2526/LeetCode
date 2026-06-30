class Solution {
public:
    int mySqrt(int x) {
        int odd = 1;
        int ans = 0;
        while (x >= odd) {
            x -= odd;
            odd += 2;
            ans++;
        }
        return ans;
    }
};