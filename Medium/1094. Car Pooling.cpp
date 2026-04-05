#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pick(1001, 0);
        vector<int> drop(1001, 0);

        int n = trips.size();
        int maxDrop = 0;
        int minPick = 1000;

        for (int i = 0; i < n; i++) {
            int passengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            if (passengers > capacity) return false;

            pick[from] += passengers;
            drop[to] += passengers;

            maxDrop = max(maxDrop, to);
            minPick = min(minPick, from);
        }

        int currPass = 0;

        for (int i = minPick; i <= maxDrop; i++) {
            currPass += pick[i];     
            currPass -= drop[i];     

            if (currPass > capacity) return false;
        }

        return true;
    }
};