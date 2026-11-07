class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<pair<int,int>> avail;
        set<tuple<long long,int,int>> busy;

        for(int i = 0; i < servers.size(); i++) {
            avail.insert({servers[i], i});
        }

        int n = tasks.size();
        vector<int> res(n);
        long long time = 0;

        for(int i = 0; i < n; i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(*busy.begin()) <= time) {
                auto [t, w, idx] = *busy.begin();
                busy.erase(busy.begin());
                avail.insert({w, idx});
            }

            if(avail.empty()) {
                time = get<0>(*busy.begin());

                while(!busy.empty() && get<0>(*busy.begin()) <= time) {
                    auto [t, w, idx] = *busy.begin();
                    busy.erase(busy.begin());
                    avail.insert({w, idx});
                }
            }

            auto [w, idx] = *avail.begin();
            avail.erase(avail.begin());

            res[i] = idx;
            busy.insert({time + tasks[i], w, idx});
        }

        return res;
    }
};