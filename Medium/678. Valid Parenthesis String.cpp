class Solution {
public:
    bool checkValidString(string s) {
        int prn = 0;
        int xtra = 0;

        for (char c : s) {
            if (c == '(') prn++;
            else if (c == ')') {
                if (prn > 0) prn--;
                else if (xtra > 0) xtra--;
                else return false;
            }
            else xtra++;
            if
        }

        return prn <= xtra;
    }
};