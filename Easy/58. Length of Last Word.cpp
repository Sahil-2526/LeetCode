class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int count = 0;
        while (i >= 0) {
            if (s[i] != ' ') {
                count++;
            }
            else if (count > 0) {
                break;
            }
            i--;
        }
        return count;
    }
};