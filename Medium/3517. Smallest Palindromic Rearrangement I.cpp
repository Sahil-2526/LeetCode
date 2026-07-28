class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> chars(26, 0);
        int n = s.length();
        for (int i = 0; i < n / 2; i++){
            chars[s[i] - 'a']++;
        }
        string left = "";
        for (int i = 0; i < 26; i++){
            left += string(chars[i], char('a' + i));
        }
        string middle = "";
        if (n % 2) middle += s[n / 2];
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};