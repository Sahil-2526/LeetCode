class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    State better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;
        return a.ids < b.ids ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; ++i) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1]) return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<long long> rights(n);

        for (int i = 0; i < n; ++i)
            rights[i] = a[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; ++i) {
            prev[i] = lower_bound(
                rights.begin(),
                rights.begin() + i,
                a[i][0]
            ) - rights.begin();
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; ++i) {
            auto [l, r, w, idx] = a[i - 1];

            for (int k = 1; k <= 4; ++k) {
                State skip = dp[i - 1][k];

                State take = dp[prev[i - 1]][k - 1];
                take.score += w;

                auto pos = lower_bound(
                    take.ids.begin(),
                    take.ids.end(),
                    (int)idx
                );

                take.ids.insert(pos, (int)idx);

                dp[i][k] = better(skip, take);
            }
        }

        return dp[n][4].ids;
    }
};