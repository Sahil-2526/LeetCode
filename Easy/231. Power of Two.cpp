using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        long long val = 1;
        while(val <= n){
            if(val == n) return true;
            val *= 2;
        }
        return false;
    }
};