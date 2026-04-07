#include<vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int m=bookings.size();

        vector<int> result(n,0);
        for(int i=0;i<m;i++){
            int l=bookings[i][0]-1;
            int r=bookings[i][1];
            int val=bookings[i][2];
            result[l]+=val;
            if(r<n) result[r]-=val;
        }

        for(int i=1;i<n;i++){
            result[i]=result[i-1]+result[i];
        }

        return result;
    }
};