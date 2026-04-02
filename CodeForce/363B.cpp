#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int current_sum = 0;
    for(int i = 0; i < k; i++) current_sum += a[i];

    int min_sum = current_sum;
    int index = 0; 

    for(int i = k; i < n; i++){
        current_sum += a[i];
        current_sum -= a[i - k];

        if(current_sum < min_sum){
            min_sum = current_sum;
            index = i - k + 1;
        }
    }

    cout << index + 1 << endl;
}