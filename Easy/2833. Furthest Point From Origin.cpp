class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        int res=0;
        int xtra=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L') res--;
            else if(moves[i]=='R') res++;
            else xtra++;
        }
        return abs(res)+xtra;
    }
};