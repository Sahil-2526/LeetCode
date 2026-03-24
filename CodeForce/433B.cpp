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

    vector<long long> prefixSum(n+1, 0);
    vector<long long> sortPrefixSum(n+1, 0);

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
            cout << prefixSum[r] - prefixSum[l-1] << endl;
        }
        else{
            cout << sortPrefixSum[r] - sortPrefixSum[l-1] << endl;
        }
    }

    return 0;
}