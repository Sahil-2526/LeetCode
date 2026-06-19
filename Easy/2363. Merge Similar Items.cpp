class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin(),items1.end(),[](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        sort(items2.begin(),items2.end(),[](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        
        vector<vector<int>> ret;

        int i = 0, j = 0;
        int n = items1.size();
        int m = items2.size();

        while (i < n && j < m) {
            if (items1[i][0] == items2[j][0]) {
                ret.push_back({items1[i][0], items1[i][1] + items2[j][1]});
                i++;
                j++;
            }
            else if (items1[i][0] < items2[j][0]) {
                ret.push_back(items1[i]);
                i++;
            }
            else {
                ret.push_back(items2[j]);
                j++;
            }
        }

        while (i < n) {
            ret.push_back(items1[i]);
            i++;
        }

        while (j < m) {
            ret.push_back(items2[j]);
            j++;
        }

        return ret;
    }
};