class Solution {
public:
    string solve(string s, string target, int pos) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        for (int i = 0; i < pos; i++) {
            int x = target[i] - 'a';

            if (freq[x] == 0)
                return "";

            ans += target[i];
            freq[x]--;
        }

        int x = target[pos] - 'a';

        for (int i = x + 1; i < 26; i++) {
            if (freq[i] > 0) {
                ans += char('a' + i);
                freq[i]--;

                for (int j = 0; j < 26; j++) {
                    while (freq[j] > 0) {
                        ans += char('a' + j);
                        freq[j]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }

    string lexGreaterPermutation(string s, string target) {
        for (int i = target.size() - 1; i >= 0; i--) {
            string ans = solve(s, target, i);

            if (ans != "")
                return ans;
        }

        return "";
    }
};