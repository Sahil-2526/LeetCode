
#include <string>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.length();
        int verti=0;
        int hori=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U') verti++;
            if(moves[i]=='D') verti--;
            if(moves[i]=='L') hori--;
            if(moves[i]=='R') hori++;
        }
        if(verti==0 && hori==0) return true;
        return false;
    }
};