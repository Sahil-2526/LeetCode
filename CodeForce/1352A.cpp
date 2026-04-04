#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;

        string n = to_string(x);
        int len = n.length();

        vector<int> ans;

        for(int j = 0; j < len; j++){
            if(n[j] != '0'){
                int place = 1;
                for(int k = 0; k < len - j - 1; k++) place *= 10;

                ans.push_back((n[j]-'0') * place);
            }
        }

        cout << ans.size() << endl;
        for(int val : ans) cout << val << " ";
        cout << endl;
    }
}