class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> last(m, -1);
        int j = m-1;
        for (int i = n-1; i>=0 && j>=0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }
        vector<int> result(m);
        bool usedChange = false;

        j = 0;
        for (int i=0; i<n && j<m; i++) {
            char curr = word1[i];
            char req = word2[j];
            bool match = (curr == req);
            bool canUseChange = !usedChange && (j == m-1 ||i < last[j+1]);
            if (match || canUseChange) {
                result[j] = i;
                if (!match) usedChange = true;
                j++;
            }
        }
        if (j < m) {
            return {};
        }
        return result;
    }
};