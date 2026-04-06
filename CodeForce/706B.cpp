#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        int idx = upper_bound(a.begin(),a.end(),x) - a.begin();
        if(idx==0) cout<<0<<endl;
        else cout<<idx<<endl;
    }
}