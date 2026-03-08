using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++){
            vector<int> r;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    r.push_back(1);
                }
                else{
                    r.push_back(result[i-1][j-1] + result[i-1][j]);
                }
            }

            result.push_back(r);
        }

        return result;
    }
};