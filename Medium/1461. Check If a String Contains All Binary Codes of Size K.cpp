#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (k > n) return false;
        set<string> sa; 
        string a = "";
        for (int i = 0; i < k - 1; i++) {
            a += s[i];
        }
        for (int i = k - 1; i < n; i++) {
            a += s[i];
            sa.insert(a);
            a.erase(0, 1);
        }
        return sa.size() == pow(2, k);
    }
};