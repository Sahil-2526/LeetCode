class Solution {
public:
    vector<vector<int>> dp;

    int profit(vector<int>& piles, int idx, int M) {
        int n = piles.size();
        if (idx >= n) return 0;
        if (idx + 2 * M >= n) {
            int sum = 0;
            for (int i = idx; i < n; i++) sum += piles[i];
            return sum;
        }
        if (dp[idx][M] != INT_MIN) return dp[idx][M];

        int val = INT_MIN;
        int taken = 0;
        for (int x = 1; x <= 2 * M; x++) {
            taken += piles[idx + x - 1];
            int oppo = profit(piles, idx + x, max(M, x));
            val = max(val, taken - oppo);
        }
        return dp[idx][M] = val;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n + 1, INT_MIN));
        int total = 0;
        for (int x : piles) total += x;
        int diff = profit(piles,0,1);
        return (total + diff) / 2;
    }
};

// we use a dp to store maximum profit for each index and M value.
// We loop over the possible number of piles to take and calculate the profit for each option.
//  We return the maximum profit at the end.
//  The final answer is (total+diff)/ 2 to get Alice's score.

// alice+bob = total
// alice-bob = diff
// alice = (total+diff)/2
// bob = (total-diff)/2