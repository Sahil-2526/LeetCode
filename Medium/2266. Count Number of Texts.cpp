class Solution {
public:
    const long long MOD = 1000000007;

    int countTexts(string pressedKeys) {

        int n = pressedKeys.size();

        vector<long long> f3(n + 1), f4(n + 1);

        f3[0] = f4[0] = 1;

        for(int i = 1; i <= n; i++) { // f(n) = f(n-1) + f(n-2) + f(n-3)

            f3[i] = f3[i-1];
            if(i >= 2) f3[i] = (f3[i] + f3[i-2]) % MOD;
            if(i >= 3) f3[i] = (f3[i] + f3[i-3]) % MOD;

            f4[i] = f4[i-1];                         // g(n) = g(n-1) + g(n-2) + g(n-3) + g(n-4)
            if(i >= 2) f4[i] = (f4[i] + f4[i-2]) % MOD;
            if(i >= 3) f4[i] = (f4[i] + f4[i-3]) % MOD;
            if(i >= 4) f4[i] = (f4[i] + f4[i-4]) % MOD;
        }

        long long result = 1;
        int count = 1;

        for(int i = 1; i < n; i++) {

            if(pressedKeys[i] == pressedKeys[i-1])
                count++;
            else {

                if(pressedKeys[i-1] == '7' || pressedKeys[i-1] == '9')
                    result = (result * f4[count]) % MOD;
                else
                    result = (result * f3[count]) % MOD;

                count = 1;
            }
        }

        if(pressedKeys[n-1] == '7' || pressedKeys[n-1] == '9')
            result = (result * f4[count]) % MOD;
        else
            result = (result * f3[count]) % MOD;

        return result;
    }
};



//-------------------------------------------------------------------------------------------




class Solution {
public:
    const long long MOD = 1000000007;
    vector<vector<long long>> dp, dp4;

    Solution() {
        dp = vector<vector<long long>>(100001, vector<long long>(4, -1));
        dp[0][0] = 1;
        dp[0][1] = dp[0][2] = dp[0][3] = 0;

        dp4 = vector<vector<long long>>(100001, vector<long long>(5, -1));
        dp4[0][0] = 1;
        dp4[0][1] = dp4[0][2] = dp4[0][3] = dp4[0][4] = 0;
    }

    void find(int n, char m) {
        if (n < 0) return;

        if (m != '7' && m != '9') {
            if (dp[n][0] != -1) return;
        } 
        else {
            if (dp4[n][0] != -1) return;
        }

        find(n - 1, m);

        if (m != '7' && m != '9') {

            dp[n][0] = 0;
            dp[n][1] = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3]) % MOD;
            dp[n][2] = (dp[n-1][0] + dp[n-1][1]) % MOD;
            dp[n][3] = dp[n-1][2] % MOD;

        } 
        else {

            dp4[n][0] = 0;
            dp4[n][1] = (dp4[n-1][0] + dp4[n-1][1] + dp4[n-1][2] + dp4[n-1][3] + dp4[n-1][4]) % MOD;
            dp4[n][2] = (dp4[n-1][0] + dp4[n-1][1]) % MOD;
            dp4[n][3] = dp4[n-1][2] % MOD;
            dp4[n][4] = dp4[n-1][3] % MOD;

        }
    }

    int countTexts(string pressedKeys) {

        int n = pressedKeys.length();
        long long result = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {

            if (pressedKeys[i] == pressedKeys[i - 1]) {
                count++;
            } 
            else {

                char m = pressedKeys[i-1];

                find(count - 1, m);

                long long ways;

                if (m != '7' && m != '9') {
                    ways = (dp[count-1][0] + dp[count-1][1] +
                            dp[count-1][2] + dp[count-1][3]) % MOD;
                } 
                else {
                    ways = (dp4[count-1][0] + dp4[count-1][1] +
                            dp4[count-1][2] + dp4[count-1][3] +
                            dp4[count-1][4]) % MOD;
                }

                result = (result * ways) % MOD;
                count = 1;
            }
        }

        char m = pressedKeys[n-1];

        find(count - 1, m);

        long long ways;

        if (m != '7' && m != '9') {
            ways = (dp[count-1][0] + dp[count-1][1] +
                    dp[count-1][2] + dp[count-1][3]) % MOD;
        } 
        else {
            ways = (dp4[count-1][0] + dp4[count-1][1] +
                    dp4[count-1][2] + dp4[count-1][3] +
                    dp4[count-1][4]) % MOD;
        }

        result = (result * ways) % MOD;

        return result;
    }
};

// 1 -> 1                   0-1 ; 1-0 ; 2-0 ; 3-0
// 11 ->  1,1 ; 11                     0-0 ; 1-1 ; 2-1 ; 3-0
// 111 -> 1,1,1 ; 1,11 ; 11,1 ; 111        0-0 ; 1-2 ; 2-1 ; 3-1 
// 1111 -> 1,1,1,1 ; 11,1,1 ; 1,11,1 ; 1,1,11 ; 111,1 ; 1,111 ; 11,11   0-0;1-4;2-2;3-1

// 0 - 1,2          
// 1 - 1,2     1=(0+1+2+3)
// 2 - 1,3     2=(0+1)
// 3 - 1       3=(2)

// 7,9 -> 3 - 1,4 ; 4- 1