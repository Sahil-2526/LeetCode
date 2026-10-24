class Solution {
public:
    int daysPassed(string s, vector<int> ps){
        return ps[stoi(s.substr(0, 2))-1] + stoi(s.substr(3, 2));
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> ps(13, 0);

        for(int i=1; i<=12; i++){
            ps[i] = ps[i-1]+days[i-1];
        }

        int start = max(daysPassed(arriveAlice, ps), daysPassed(arriveBob, ps));
        int end = min(daysPassed(leaveAlice, ps), daysPassed(leaveBob, ps));

        return (end < start) ? 0 : end-start+1;
    }
};