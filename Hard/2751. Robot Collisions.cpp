#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> stk; 

        for (int idx : indices) {
            if (directions[idx] == 'R') {
                stk.push(idx);
            } else {
                
                while (!stk.empty() && healths[idx] > 0) {
                    int topIdx = stk.top();

                    if (healths[topIdx] < healths[idx]) {
                        healths[topIdx] = 0;
                        healths[idx] -= 1;
                        stk.pop();
                    } else if (healths[topIdx] > healths[idx]) {
                        healths[topIdx] -= 1;
                        healths[idx] = 0; 
                    } else {
                        healths[topIdx] = 0;
                        healths[idx] = 0;
                        stk.pop();
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};