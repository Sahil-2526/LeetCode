class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        map<int, pair<int, int>> mp;
        for (int x : nums) {
            int len = 0;
            int ways = 0;
            for (auto it = mp.begin(); it != mp.lower_bound(x); it++) {
                if (it->second.first > len) {
                    len = it->second.first;
                    ways = it->second.second;
                }
                else if (it->second.first == len) ways += it->second.second;
            }

            if (len == 0) {
                len = 1;
                ways = 1;
            }
            else {
                len++;
            }
            
            if (mp.count(x)) {
                if (mp[x].first < len) mp[x] = {len, ways};
                else if (mp[x].first == len) mp[x].second += ways;
            }
            else mp[x] = {len, ways};
        }

        int mx = 0;
        int ans = 0;
        for (auto &[value, p] : mp) {
            if (p.first > mx) {
                mx = p.first;
                ans = p.second;
            }
            else if (p.first == mx) ans += p.second;
        }
        return ans;
    }
};