class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for (long long pens = 0; pens * cost1 <= total; pens++) {
            long long rem = total - pens * cost1;
            ans += rem / cost2 + 1;
        }
        return ans;
    }
};