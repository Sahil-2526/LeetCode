#include <string>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        int N=n.length();
        int max=0;
        for(int i=0;i<N;i++) {
            int digit=n[i]-'0'; 
            if(max<digit) max=digit;
        }
        return max;
    }
};