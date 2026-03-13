#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        multiset<tuple<long long,long long,long long>> st; 
        for (auto &a : workerTimes) {
            st.insert({a, a, 2});
        }
        long long k = 0;
        long long t = 0;
        while (k < mountainHeight) {
            t = get<0>(*st.begin());
            vector<tuple<long long,long long,long long>> removed;
            while (!st.empty() && get<0>(*st.begin()) == t) {
                removed.push_back(*st.begin());
                st.erase(st.begin());
            }
            k += removed.size();
            for (auto &p : removed) {
                long long a = get<0>(p);
                long long b = get<1>(p);
                long long c = get<2>(p);
                st.insert({a + b*c, b, c+1});
            }
        }
        return t;
    }
};