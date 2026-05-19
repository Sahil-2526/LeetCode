#include<set>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(int i=0 ;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0 ;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        vector<int> result;
        for (auto it = s2.begin(); it != s2.end(); it++) {
            if(s1.find(*it)!=s1.end()){
                result.push_back(*it);
            }
        }
        return result;
    }
};

-------------------------------------------------------------------


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        set<int> elem;
        for(int x:nums1){
            if(elem.find(x)==elem.end()) elem.insert(x);
        }
        for(int x:nums2){
            if(elem.find(x)!=elem.end() ) res.insert(x);
        }
        vector<int> result;
        for(int x:res) result.push_back(x);
        return result;
    }
};