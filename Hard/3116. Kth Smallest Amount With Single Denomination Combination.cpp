class Solution {
public:
    typedef long long ll;
    ll findPos(ll num, vector<int>& coins) {
        int n = coins.size();
        ll res = 0;
        for (int i=1; i <= (1<<n)-1; i++) {
            ll lcm = 0;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    if (lcm == 0) lcm = coins[j];
                    else lcm = (lcm * coins[j]) / gcd(lcm, (ll)coins[j]);
                }
            }
            if (cnt % 2 == 1)res += num/lcm;
            else res -= num/lcm;
        }
        return res;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll l = 1;
        ll r = (ll)*max_element(coins.begin(), coins.end()) * k;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            if (findPos(m, coins) >= k) r = m-1;
            else l = m+1;
        }
        return l;
    }
};