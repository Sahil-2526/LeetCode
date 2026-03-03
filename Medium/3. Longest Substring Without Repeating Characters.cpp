#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<vector<int>> a(2, vector<int>(128, 0)); 
        int count = 0;
        int ans = 0;
        int start = 0;  

        for (int i = 0; i < s.length(); i++) {
            int num = (int)s[i];

            if (a[0][num] == 1) {
                start = max(start, a[1][num] + 1);
                count = i - start + 1;
                a[1][num] = i; 
            } else {
                a[0][num] = 1;
                a[1][num] = i;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};