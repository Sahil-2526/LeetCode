#include <unordered_map>
#include <string>

class Solution {
public:
    string getHappyString(int n, int k) {
        k--;  

        unordered_map<int,char> amy;
        amy[0] = 'a';
        amy[1] = 'b';
        amy[2] = 'c';

        long long total = 3LL << (n-1);

        if(k >= total) return "";

        string op = "";
        int prev = -1;
        bool isFirst = true;

        while(n--) {
            long long num;

            if(isFirst){
                num = total / 3;
                isFirst = false;
            } else {
                num = total / 2;
            }

            int idx = k / num;

            if(idx >= prev && prev != -1) idx++;

            op += amy[idx];
            prev = idx;

            k %= num;
            total = num;
        }

        return op;
    }
};