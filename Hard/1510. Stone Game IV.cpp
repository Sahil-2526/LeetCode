class Solution {
public:
    bool winnerSquareGame(int n){
        vector<bool> dp(n+1, false);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                if(dp[i - j*j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n]; 
    }
};

// we use a dp to store whether the current player can win with n stones left.
// We loop over the possible square numbers to take and check if the opponent can win with the remaining stones.
// If the opponent cannot win, then the current player can win by taking that square number of stones.
// We return the value of dp[n] at the end, which indicates whether the first player can win with n stones.