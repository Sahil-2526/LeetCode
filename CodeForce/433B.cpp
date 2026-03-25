#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    vector<long long> sortedInput = input;
    sort(sortedInput.begin(), sortedInput.end());

    vector<long long> prefixSum(n+1, 0); // find prefix sum of input 
    vector<long long> sortPrefixSum(n+1, 0); // prefix sum of sorted input

    for(int i = 1; i <= n; i++){
        prefixSum[i] = prefixSum[i-1] + input[i-1];
        sortPrefixSum[i] = sortPrefixSum[i-1] + sortedInput[i-1];
    }

    int q;
    cin >> q;

    while(q--){
        int t, l, r;
        cin >> t >> l >> r;

        if(t == 1){
            cout << prefixSum[r] - prefixSum[l-1] << endl; // sum of input from l to r = prefixSum[r] - prefixSum[l-1]
        }
        else{
            cout << sortPrefixSum[r] - sortPrefixSum[l-1] << endl; // sum of sorted input from l to r = sortPrefixSum[r] - sortPrefixSum[l-1]
        }
    }

    return 0;
}