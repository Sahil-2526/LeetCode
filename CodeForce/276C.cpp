#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<long long> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    vector<long long> freq(n+1, 0);

    while(q--){
        int l, r;
        cin >> l >> r;
        freq[l-1] += 1;
        if(r < n) freq[r] -= 1;
    }

    for(int i = 1; i < n; i++){
        freq[i] += freq[i-1];
    }

    sort(input.begin(), input.end());
    sort(freq.begin(), freq.begin()+n);

    long long result = 0;
    for(int i = 0; i < n; i++){
        result += input[i] * freq[i];
    }

    cout << result << endl;
    return 0;
}