#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const long long base = 31;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<long long> power(n+1,1), hash(n+1,0);

    for(int i=1;i<=n;i++){
        power[i] = (power[i-1]*base)%MOD;
    }

    for(int i=0;i<n;i++){
        hash[i+1] = (hash[i]*base + (s[i]-'a'+1))%MOD;
    }

    auto getHash = [&](int l, int r){
        long long h = (hash[r+1] - hash[l]*power[r-l+1]%MOD + MOD)%MOD;
        return h;
    };

    vector<int> candidates;

    for(int len=1; len<n; len++){
        if(getHash(0,len-1) == getHash(n-len,n-1)){
            candidates.push_back(len);
        }
    }

    reverse(candidates.begin(), candidates.end());

    for(int len : candidates){
        for(int i=1;i+len-1<n-1;i++){
            if(getHash(i,i+len-1) == getHash(0,len-1)){
                cout << s.substr(0,len);
                return 0;
            }
        }
    }

    cout << "Just a legend";
}