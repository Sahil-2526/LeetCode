class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> sml(0), cap(0), valid;
        valid.set();
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                cap.set(word[i] - 'A');
            }
            if (word[i] >= 'a' && word[i] <= 'z') {
                sml.set(word[i] - 'a');
                if( cap[word[i] - 'a'] ) valid.reset(word[i] - 'a');
            }
        }
        return (sml & cap & valid).count();
    }
};