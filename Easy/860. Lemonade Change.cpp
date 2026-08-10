class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> mny(2,0);
        for(int x: bills){
            if(x == 20){
                if(mny[1] > 0 && mny[0] > 0){
                    mny[1]--;
                    mny[0]--;
                }
                else if(mny[0] >= 3){
                    mny[0]-=3;
                }
                else return false;
            }
            else if(x == 10){
                if(mny[0] >= 1){
                    mny[0]--;
                    mny[1]++;
                }
                else return false;
            }
            else mny[0]++;
        }
        return true;
    }
};