#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    int sereja = 0, dima = 0;
    int chance = 0;

    while(l <= r){
        int val;
        if(arr[l] > arr[r]){
            val = arr[l];
            l++;
        } else {
            val = arr[r];
            r--;
        }

        if(chance % 2 == 0) sereja += val;
        else dima += val;

        chance++;
    }

    cout << sereja << " " << dima;

    return 0;
}