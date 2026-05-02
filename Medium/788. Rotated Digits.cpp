class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            int k = i;
            bool valid = true;
            bool changed = false;

            while (k > 0) {
                int r = k % 10;

                if (r == 3 || r == 4 || r == 7) {
                    valid = false;
                    break;
                }

                if (r == 2 || r == 5 || r == 6 || r == 9) {
                    changed = true;
                }

                k /= 10;
            }

            if (valid && changed) {
                count++;
            }
        }

        return count;
    }
};