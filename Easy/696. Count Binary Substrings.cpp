#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;  
        int cur = 1;   
        int count = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                cur++;                
            } else {
                count += min(prev, cur);
                prev = cur;            
                cur = 1;                
            }
        }

        count += min(prev, cur);
        return count;
    }
};