#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    int t;
    cin >> t; // number of test cases

    while (t--) {
        int n;
        cin >> n; // size of the array

        vector<long long> a(n); // input array
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n; i++) {
            vector<long long> left, right; 

            for (int j = i + 1; j < n; j++) {  // storing elements to the left and right of a[i]
                if (a[j] < a[i]) left.push_back(a[j]);
                else if (a[j] > a[i]) right.push_back(a[j]);
            }

            double k = 0;

            if (left.size() >= right.size()) { // finding k based on the elements to the left and right of a[i]
                if (!left.empty()) {
                    long long mn = *min_element(left.begin(), left.end());
                    long long mx = *max_element(left.begin(), left.end());
                    k = (mn + mx) / 2.0;
                }
            } else {
                if (!right.empty()) {
                    long long mn = *min_element(right.begin(), right.end());
                    long long mx = *max_element(right.begin(), right.end());
                    k = (mn + mx) / 2.0;
                }
            }

            int count = 0;

            for (int j = i + 1; j < n; j++) {  // checking condition for counting
                if (abs(a[i] - k) > abs(a[j] - k)) {
                    count++;
                }
            }

            cout << count << " ";
        }

        cout << "\n";
    }
} 