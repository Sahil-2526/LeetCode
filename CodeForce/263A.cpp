#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<vector<int>> a(5, vector<int>(5));

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) { 
            cin >> a[i][j];
        }
    }

    int ans_i = 0, ans_j = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {  
            if(a[i][j] == 1) {
                ans_i = i;
                ans_j = j;
            }
        }
    }

    cout << abs(ans_i - 2) + abs(ans_j - 2) << endl; 

    return 0;
}