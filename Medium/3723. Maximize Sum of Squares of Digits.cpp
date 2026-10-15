class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        string ans = "";

        for (int i = 0; i < num; i++) {
            int x = min(9, sum);
            ans += char('0' + x);
            sum -= x;
        }

        return ans;
    }
};