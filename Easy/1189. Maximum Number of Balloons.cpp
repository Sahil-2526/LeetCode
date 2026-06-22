class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(5,0);
        for(char x: text){
            if( x == 'b') count[0]++;
            if( x == 'a') count[1]++;
            if( x == 'l') count[2]++;
            if( x == 'o') count[3]++;
            if( x == 'n') count[4]++;
        }
        int inst = INT_MAX;
        for(int i=0;i<5;i++){
            if( i==2 || i==3) inst = min(inst, count[i]/2);
            else inst = min(inst, count[i]);
        }
        return inst;
    }
};