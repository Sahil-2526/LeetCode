class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                upperCount++;
            }
        }
        if (upperCount == n) return true;
        if (upperCount == 0) return true;
        if (upperCount == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;
        return false;
    }
};