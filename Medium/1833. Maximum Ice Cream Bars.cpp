class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for(int x: costs){
            if(x > coins) break;
            else{
                res++;
                coins-=x;
            }
        }
        return res;
    }
};