class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int l = 0, r = 0;
        int ls = 0, rs = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') l++;
            else ls += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') r++;
            else rs += num[i] - '0';
        }

        int q = l-r;
        int s = ls-rs;

        return q % 2 != 0 || s != -9*q/2 ;
    }
};

