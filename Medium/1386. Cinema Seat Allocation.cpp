class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int l = -1;
        int h = 11;
        sort(reservedSeats.begin(), reservedSeats.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });
        int r = reservedSeats[0][0];
        int c = 1;
        long long res = 0;
        for(auto& a : reservedSeats) {
            if(a[0] != r) {
                if(h >= 10 && l <= 1) res += 2;
                else if((h >= 6 && l <= 1) ||  (h >= 8 && l <= 3) || (h >= 10 && l <= 5)) res++;
                r = a[0];
                c++;
                l=-1;
                h=11;
            }
            if(a[1] <= 5) l = max(l, a[1]);
            if(a[1] > 5) h = min(h, a[1]);
        }

        if(h >= 10 && l <= 1) res += 2;
        else if((h >= 6 && l <= 1) ||  (h >= 8 && l <= 3) || (h >= 10 && l <= 5)) res++;

        res += 2LL * (n - c);

        return res;
    }
};