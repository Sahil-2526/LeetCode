class Solution {
public:
    vector<vector<int>> dp;
    int maxScore(int i, int j, vector<int>& val) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for (int k = i; k < j; k++) {
            int left = val[k + 1] - val[i];
            int right = val[j + 1] - val[k + 1];

            if (left < right) ans = max(ans, left + maxScore(i, k, val));
            else if (left > right) ans = max(ans, right + maxScore(k + 1, j, val));
            else ans = max(ans, left + max(maxScore(i, k, val),maxScore(k + 1, j, val)));
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int sum=0;
        int len=stoneValue.size();
        vector<int> val(len + 1, 0);
        for (int i = 0; i < len; i++) {
            val[i + 1] = val[i] + stoneValue[i];
        }

        dp = vector<vector<int>>(len, vector<int>(len, -1));
        return maxScore(0,len-1,val);
    }
};

// we use dp to store the maximum score for each subarray of stoneValue
// we loop over all possible subarrays and calculate the score for each subarray by comparing the left and right sums of the subarray and adding the maximum score of the left or right subarray
// we return the maximum score for the entire array at the end