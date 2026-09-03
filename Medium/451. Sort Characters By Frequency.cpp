class Solution {
public:
    string frequencySort(string s) {
        vector<string> str(62, "");

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                str[s[i] - 'a'] += s[i];

            else if (s[i] >= 'A' && s[i] <= 'Z')
                str[s[i] - 'A' + 26] += s[i];

            else
                str[s[i] - '0' + 52] += s[i];
        }

        sort(str.begin(), str.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });

        string res;

        for (int i = 0; i < 62; i++)
            res += str[i];

        return res;
    }
};