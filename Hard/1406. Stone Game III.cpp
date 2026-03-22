class Solution {
public:
    vector<int> dp;

    int profit(vector<int>& piles, int idx) {
        int n = piles.size();

        if (idx >= n) return 0;

        if (dp[idx] != INT_MIN) return dp[idx];

        int val = INT_MIN;
        int taken = 0;

        for (int x = 1; x <= 3 && idx + x <= n; x++) {
            taken += piles[idx + x - 1];
            int oppo = profit(piles, idx + x);
            val = max(val, taken - oppo);
        }

        return dp[idx] = val;
    }

    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, INT_MIN);
        int diff = profit(piles, 0);
        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};

// we use a dp to store maximum profit for each index.
// We loop over the possible number of piles to take and calculate the profit for each option.
//  We return the maximum profit at the end. If the profit is positive, Alice wins
// If the profit is negative, Bob wins. If the profit is 0, it's a tie.