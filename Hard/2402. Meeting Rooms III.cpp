class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        set<int> avail;
        for(int i = 0; i < n; i++){
            avail.insert(i);
        }
        set<pair<long long, int>> busy;
        vector<int> num(n, 0);
        for(int i = 0; i < meetings.size(); i++){
            long long st = meetings[i][0];
            long long dur = meetings[i][1]-meetings[i][0];
            while(!busy.empty() && busy.begin()->first <= st){
                avail.insert(busy.begin()->second);
                busy.erase(busy.begin());
            }
            int room;
            long long end;
            if(!avail.empty()){
                room = *avail.begin();
                avail.erase(avail.begin());
                end = st+dur;
            }
            else{
                auto it = busy.begin();
                st = it->first;
                room = it->second;
                busy.erase(it);
                end = st + dur;
            }
            busy.insert({end, room});
            num[room]++;
        }

        int ans = 0;

        for(int i = 1; i < n; i++){
            if(num[i] > num[ans]){
                ans = i;
            }
        }

        return ans;
    }
};