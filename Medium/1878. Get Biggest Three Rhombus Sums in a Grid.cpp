#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int range = min(n, m) / 2;

        set<int> st;
        int sum;

        for(int i = 0; i <= range; i++){
            for(int j = 0; j < n - 2*i; j++){
                for(int k = 0; k < m - 2*i; k++){

                    if(i == 0){
                        sum = grid[j][k];
                    }
                    else{
                        sum = 0;

                        for(int l = 0; l < i; l++)
                            sum += grid[j+l][k+i+l];

                        for(int l = 0; l < i; l++)
                            sum += grid[j+i+l][k+2*i-l];

                        for(int l = 0; l < i; l++)
                            sum += grid[j+2*i-l][k+i-l];

                        for(int l = 0; l < i; l++)
                            sum += grid[j+i-l][k+l];
                    }

                    st.insert(sum);

                    if(st.size() > 3)
                        st.erase(st.begin());
                }
            }
        }

        vector<int> ans(st.rbegin(), st.rend());
        return ans;
    }
};

// first we run a loop for all possible value of rhombus
// inside it we make 2 loops to to move the rhombus and find the maximum value inside 
// then in the inner most we find the sum of vertices and edge of rhombus 
// we use 4 loop for finding sum ;  top to right ; right to bottom ; bottom to left ; left to top
// we use set to store the sum and if size of set is greater than 3 we remove the first element of set ( smallest one )
// at the end we copy the element of set in vector ( in opposite order ) and return it 