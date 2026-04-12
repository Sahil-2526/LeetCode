#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[301][27]; 

    int dist(int a, int b){
        if(a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int i, string &word, int other){
        if(i == word.size()) return 0;

        if(dp[i][other + 1] != -1)
            return dp[i][other + 1];

        int curr = word[i] - 'A';
        int prev = word[i - 1] - 'A';

        int useSame = dist(prev, curr) + solve(i + 1, word, other);

        int useOther = dist(other, curr) + solve(i + 1, word, prev);

        return dp[i][other + 1] = min(useSame, useOther);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(1, word, -1); 
    }
};