class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        if (n > 0) {
            tree.assign(4 * n, 0);
            build(1, 0, n - 1, arr);
        }
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(node * 2, start, mid, arr);
        build(node * 2 + 1, mid + 1, end, arr);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = start + (end - start) / 2;

        return max(query(node * 2, start, mid, l, r),
                   query(node * 2 + 1, mid + 1, end, l, r));
    }

    int rangeMax(int l, int r) {
        if (n == 0 || l > r)
            return 0;

        l = max(l, 0);
        r = min(r, n - 1);

        if (l > r)
            return 0;

        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = 0;
        vector<pair<int, int>> zeroes;  
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0')
                    j++;
                zeroes.push_back({i, j - 1});
                i = j;
            } else {
                ones++;
                i++;
            }
        }
        if (zeroes.size() < 2) return vector<int>(queries.size(), ones);
        vector<int> pairs;
        for (int i = 1; i < zeroes.size(); i++) {
            auto [l1, r1] = zeroes[i - 1];
            auto [l2, r2] = zeroes[i];
            pairs.push_back((r1 - l1 + 1) + (r2 - l2 + 1));
        }
        SegmentTree st(pairs);
        vector<int> starts, ends;
        for (auto &[l, r] : zeroes) {
            starts.push_back(l);
            ends.push_back(r);
        }
        vector<int> res;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int first = lower_bound(ends.begin(), ends.end(), l) - ends.begin();
            int last = upper_bound(starts.begin(), starts.end(), r) - starts.begin() - 1;
            if (first >= last) {
                res.push_back(ones);
                continue;
            }
            int best = st.rangeMax(first + 1, last - 2);
            int prev1 = min(zeroes[first].second, r) - max(zeroes[first].first, l) + 1;
            int next1 = min(zeroes[first + 1].second, r) - max(zeroes[first + 1].first, l) + 1;
            best = max(best, prev1 + next1);
            prev1 = min(zeroes[last - 1].second, r) - max(zeroes[last - 1].first, l) + 1;
            next1 = min(zeroes[last].second, r) - max(zeroes[last].first, l) + 1;
            best = max(best, prev1 + next1);
            res.push_back(ones + best);
        }
        return res;
    }
};