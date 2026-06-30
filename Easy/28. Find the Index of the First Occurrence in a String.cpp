class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (n < m) return -1;
        int nVal = 0, hVal = 0;
        for (int i = 0; i < m; i++) {
            nVal += needle[i] - 'a';
            hVal += haystack[i] - 'a';
        }
        for (int i = 0; i <= n - m; i++) {
            if (nVal == hVal) {
                bool valid = true;
                for (int j = 0; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return i;
            }
            if (i < n - m) {
                hVal -= haystack[i] - 'a';
                hVal += haystack[i + m] - 'a';
            }
        }
        return -1;
    }
};