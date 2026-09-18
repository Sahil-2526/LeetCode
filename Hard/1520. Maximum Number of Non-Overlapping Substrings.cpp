class Solution {
public:
    string s;
    vector<int> result;
    int length = INT_MAX;

    void solve(int i, vector<int>& first, vector<int>& last,
               vector<int>& sfirst, vector<int>& res, int len) {

        if(i >= sfirst.size()) {
            if(res.size() > result.size() ||
              (res.size() == result.size() && len < length)) {
                result = res;
                length = len;
            }
            return;
        }

        solve(i + 1, first, last, sfirst, res, len);

        int ch = sfirst[i];
        int l = first[ch];
        int r = last[ch];

        bool valid = true;

        for(int j = l; j <= r; j++) {
            int c = s[j] - 'a';

            if(first[c] < l) {
                valid = false;
                break;
            }

            r = max(r, last[c]);
        }

        if(valid) {
            int nxt = i + 1;

            while(nxt < sfirst.size() && first[sfirst[nxt]] <= r)
                nxt++;

            res.push_back(ch);
            solve(nxt, first, last, sfirst, res, len+r-l+1);
            res.pop_back();
        }
    }

    vector<string> maxNumOfSubstrings(string str) {
        s = str;

        vector<int> first(26, -1), last(26, -1);
        vector<int> sfirst;

        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if(first[c] == -1)
                first[c] = i;
            last[c] = i;
        }
        for(int i = 0; i < 26; i++) {
            if(first[i] != -1)
                sfirst.push_back(i);
        }

        sort(sfirst.begin(), sfirst.end(), [&](int a, int b) {
            return first[a] < first[b];
        });

        vector<int> res;

        solve(0, first, last, sfirst, res, 0);

        vector<string> ans;

        for(int c : result) {
            int l = first[c];
            int r = last[c];

            for(int j = l; j <= r; j++)
                r = max(r, last[s[j] - 'a']);

            ans.push_back(s.substr(l, r - l + 1));
        }

        return ans;
    }
};