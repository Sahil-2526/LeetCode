class Solution {
public:
    int numOfWays(int n) {
        if(n==1){
            return 12;
        }
        const int m=1e9+7;
        long long same=6;
        long long diff=6;
        for(int i=2;i<=n;i++){
             long long s=(same*3+diff*2)% m;
             long long d=(same*2+diff*2)% m;
             same=s;
             diff=d;
        }
        return (same + diff)%m;
    }
};
// 2 side same , 3 diff
// y r y 2, r y r 2
// y r g 3, r g y 3
// y g y 2, r g r 2 
// g r g 2, g y r 3
// g r y 3, 