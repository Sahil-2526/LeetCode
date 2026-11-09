class Solution {
public:
    typedef long long ll;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<pair<ll, ll>> busy;
        set<ll> avail;
        for(int i=0; i<k; i++) avail.insert(i);
        vector<ll> num(k, 0);
        int mul = 1;
        for(int i=0; i<arrival.size(); i++){
            if(i%k == 0) mul++;
            while(!busy.empty() && busy.begin()->first <= arrival[i]){
                auto it = busy.begin();
                int id = it->second;
                if(id < i%k) avail.insert(mul*k+id);
                else avail.insert((mul-1)*k+id);
                busy.erase(it);
            }
            if(avail.empty()) continue;
            auto it = avail.begin();
            int id = *it%k;
            num[id] ++;
            avail.erase(it);
            busy.insert({arrival[i]+load[i], id});
        }

        int mx = *max_element(num.begin(), num.end());
        vector<int> res;
        for(int i=0; i<k; i++){
            if(num[i] == mx) res.push_back(i);
        }
        return res;
    }
};