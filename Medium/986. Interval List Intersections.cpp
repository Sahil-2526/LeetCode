#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> result;

        int i = 0, j = 0;
        while(i < n && j < m){
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);

            if(l <= r) result.push_back({l,r});

            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }

        return result;
    }
};