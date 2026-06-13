class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for (string &word : words) {
            long long sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            int r = sum % 26;
            result.push_back('z' - r);
        }
        return result;

    }
};