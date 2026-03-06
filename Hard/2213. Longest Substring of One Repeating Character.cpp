#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int len = s.size();
        int k = queryIndices.size();
        vector<int> result(k);

        map<int, int> seg;
        multiset<int> ms;

        int start = 0;
        for(int i = 1; i <= len; i++){
            if(i == len || s[i] != s[start]){
                seg[start] = i-1;
                ms.insert(i - start);
                start = i;
            }
        }

        for(int q = 0; q < k; q++){
            int idx = queryIndices[q];
            char c = queryCharacters[q];

            if(s[idx] == c){
                result[q] = *ms.rbegin();
                continue;
            }

            auto it = seg.upper_bound(idx);
            --it;
            int l = it->first, r = it->second;
            ms.erase(ms.find(r - l + 1));
            seg.erase(it);

            if(l <= idx-1){
                seg[l] = idx-1;
                ms.insert(idx - l);
            }

            if(idx+1 <= r){
                seg[idx+1] = r;
                ms.insert(r - idx);
            }

            s[idx] = c;

            int new_l = idx, new_r = idx;
            if(idx > 0 && s[idx-1] == c){
                auto lit = seg.lower_bound(idx);
                --lit;
                new_l = lit->first;
                new_r = idx;
                ms.erase(ms.find(lit->second - lit->first +1));
                seg.erase(lit);
            }

            if(idx < len-1 && s[idx+1] == c){
                auto rit = seg.lower_bound(idx+1);
                new_r = rit->second;
                ms.erase(ms.find(rit->second - rit->first +1));
                seg.erase(rit);
            }

            seg[new_l] = new_r;
            ms.insert(new_r - new_l + 1);

            result[q] = *ms.rbegin();
        }

        return result;
    }
};