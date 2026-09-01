class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }
        int n = s.size();
        int i = 0;
        int min_win_size = INT_MAX;
        int min_i = -1, min_j = -1;
        int req = t.size();

        for (int j = 0; j < n; j++) {
            if (freq.find(s[j]) != freq.end()) {
                if (freq[s[j]] > 0) {
                    req--;
                }
                freq[s[j]]--;
            }
            while (req == 0) {
                if (min_win_size > j-i+1) {
                    min_win_size = j-i+1;
                    min_i = i;
                    min_j = j;
                }
                if (freq.find(s[i]) != freq.end()) {
                    freq[s[i]]++;
                    if (freq[s[i]] > 0) {
                        req++;
                    }
                }
                i++;
            }
        }
        if (min_i == -1) {
            return "";
        }
        return s.substr(min_i, min_win_size);
    }
};