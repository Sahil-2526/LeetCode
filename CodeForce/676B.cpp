#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;

    int l = 0, r = 0;
    int bCount = 0;
    int maxALen = 0;

    while(r < n){
        if(s[r] == 'b') bCount++;
        while(bCount > k){
            if(s[l] == 'b') bCount--;
            l++;
        }
        maxALen = max(maxALen, r - l + 1);
        r++;
    }

    l = 0;
    r = 0;
    int aCount = 0;
    int maxBLen = 0;

    while(r < n){
        if(s[r] == 'a') aCount++;
        while(aCount > k){
            if(s[l] == 'a') aCount--;
            l++;
        }
        maxBLen = max(maxBLen, r - l + 1);
        r++;
    }

    cout << max(maxALen, maxBLen) << endl;
}