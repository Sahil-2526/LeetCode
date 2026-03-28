#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        for(int i=0;i<n;i++){
            if(lcp[i][i] != n-i) return "";
            for(int j=0;j<n;j++){
                if(lcp[i][j] != lcp[j][i]) return "";
                if(i+1<n && j+1<n && lcp[i][j]>0){
                    if(lcp[i+1][j+1] != lcp[i][j]-1) return "";
                }
            }
        }
        
        vector<int> sudoAns(n, 0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int k = lcp[i][j];
                if(k>n-i || k>n-j ) return "";
                if((i+k < n) && (j+k < n)){
                    for(int l=0;l<k;l++){
                        sudoAns[i+l]=sudoAns[j+l];
                    }
                    if(sudoAns[i+k] == sudoAns[j+k]){
                        sudoAns[i+k] = sudoAns[i+k] + 1;
                    }
                }
            }
        }
        
        unordered_map<int, char> num_to_char;
        char next_char = 'a';
        string res;
        for(int i=0;i<n;i++){
            if(num_to_char.find(sudoAns[i]) == num_to_char.end()){
                if(next_char>122) return "";
                num_to_char[sudoAns[i]] = next_char++;
            }
            res.push_back(num_to_char[sudoAns[i]]);
        }

        vector<vector<int>> check(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (res[i] == res[j]) {
                check[i][j] = (i + 1 < n && j + 1 < n) ? 1 + check[i + 1][j + 1] : 1;
            } else {
                check[i][j] = 0;
            }
            
            if (check[i][j] != lcp[i][j]) return "";
        }
    }
        
        return res;
    }
};

// 1st check lcp ,
// diagonal element n-i ;  
// symmetric matrix ; 
// [i] a[i+1][j+1]=a[i][j]-1   -> if ij is matching 5 then i,j ; i+1,j+1 ; ... are matching -> i+1 , j+1 should have one less matching ( matching at start is removed )
// for every pattern , make same equal and at end ( different ) increase value of i+k by 1 , ( diff no. diff character )
// fill character , no. that comes 1st -> a , then b , then c , ... , if more than 26 characte rused -> invalid
// check if the string matches the  original lpc , if yes return string else invalid