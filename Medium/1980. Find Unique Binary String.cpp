#include <unordered_map>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,bool> mp;
        int n = nums.size();
        int len = nums[0].length();
        for(int i=0;i<n;i++){
            int num=stoi(nums[i],nullptr,2);
            mp[num]=true;
        }
        for(int i=0;i<(1<<len);i++){
            if(mp.find(i)==mp.end()){
                string result = "";
                int x = i;
                while(x>0){
                    result=char('0'+(x%2))+result;
                    x=x/2;
                }
                string frontZeros(len - result.length(), '0');
                return frontZeros + result;
            }
        }

        return "";
    }
};