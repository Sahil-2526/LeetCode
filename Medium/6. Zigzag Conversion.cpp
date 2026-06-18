class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        string res;
        int num = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++) {
            for (int j = row; j < s.size(); j += num) {
                res += s[j];
                int d = j + num - 2 * row;
                if (row != 0 && row != numRows - 1 && d < s.size()) res += s[d];
            }
        }

        return res;
    }
};