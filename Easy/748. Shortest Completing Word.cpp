class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> chars(26, 0);
        for (char c : licensePlate) {
            if(c >= 65 && c <= 90) {
                chars[c - 'A']++;
            }
            else if(c >= 97 && c <= 122) {
                chars[c - 'a']++;
            }
        }
        string ans = "";
        for (string &word : words) {
            vector<int> count(26, 0);
            for (char c : word) {
                count[c - 'a']++;
            }
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (count[i] < chars[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid == true && (ans.empty() || word.size() < ans.size())) {
                ans = word;
            }
        }

        return ans;
    }
};