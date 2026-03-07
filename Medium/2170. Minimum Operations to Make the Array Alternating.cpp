#include <vector>
#include <unordered_map>
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> even, odd;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0) even[nums[i]]++;
            else odd[nums[i]]++;
        }
        int evenMax1=0, evenMax2=0;
        int oddMax1=0, oddMax2=0;
        int evenVal1=0, oddVal1=0;

        for(auto p: even){
            if(p.second > evenMax1){
                evenMax2 = evenMax1;
                evenMax1 = p.second;
                evenVal1 = p.first;
            }
            else if(p.second > evenMax2){
                evenMax2 = p.second;
            }
        }

        for(auto p: odd){
            if(p.second > oddMax1){
                oddMax2 = oddMax1;
                oddMax1 = p.second;
                oddVal1 = p.first;
            }
            else if(p.second > oddMax2){
                oddMax2 = p.second;
            }
        }

        if(evenVal1 != oddVal1){
            return n - evenMax1 - oddMax1;
        }
        else{
            return min(n - evenMax1 - oddMax2,
                       n - evenMax2 - oddMax1);
        }
    }
};