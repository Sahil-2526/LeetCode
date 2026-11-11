class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int com = min(need1, need2);
        long long both = cost1+cost2;
        long long res = 0;
        res += com*(min((ll)costBoth, both));
        if(need1 > need2) res += (need1-need2)*(1LL*min(cost1, costBoth));
        else res += (need2-need1)*(1LL*min(cost2, costBoth));
        return res;
    }
};