#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string res(n+m-1, '-');
        vector<bool> trueStr(n+m-1,false);

        for (int i=0; i<n; i++) {
            if (str1[i] == 'T') {
                for (int j=0; j<m; j++) {
                    if (res[i+j]=='-' || res[i+j]==str2[j]) {
                        res[i+j] = str2[j];
                        trueStr[i+j]=true;
                    } else {
                        return "";
                    }
                }
            }
        }

        for(int i=0;i<n+m-1;i++){
            if(res[i]=='-') res[i]='a';
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                bool notMatch=false;

                for(int j=0;j<m;j++){
                    if(res[i+j]!=str2[j]){
                        notMatch=true;
                        break;
                    }
                }

                if(!notMatch){
                    bool fixed = false;

                    for(int j=i+m-1;j>=i;j--){
                        if(trueStr[j]==true) continue;
                        char original = res[j];

                        char c;
                        if(str2[j-i]=='a') c='b';
                        else c='a';
                        res[j] = c;

                        bool valid = true;
                        for(int k=0;k<n;k++){
                            if(str1[k]=='T'){
                                for(int x=0;x<m;x++){
                                    if(res[k+x]!=str2[x]){
                                        valid=false;
                                        break;
                                    }
                                }
                                if(!valid) break;
                            }
                        }
                        if(valid){
                            fixed = true;
                            break;
                        }

                        res[j] = original;

                        if(fixed) break;
                    }

                    if(!fixed) return "";
                }
            }
        }

        return res;
    }
};