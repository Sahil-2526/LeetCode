#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int func(int i,vector<int> &left,vector<int> &right){
    
}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    unordered_map<int,int> left;
    vector<int> lft;
    for(int i=0;i<n;i++){
        left[arr[i]]++;
        lft[i]=left[arr[i]];
    }

    unordered_map<int,int> right;
    vector<int>  rht;
    for(int i=n-1;i>0;i--){
        right[arr[i]]++;
        rht[i]=right[arr[i]];
    }



}