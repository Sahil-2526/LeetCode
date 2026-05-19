class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        multiset<int> elem;
        for(int x:nums1) elem.insert(x);
        for(int x:nums2){
            if(elem.find(x)!=elem.end()){
                result.push_back(x);
                auto it = elem.find(x);
                if (it != elem.end()) elem.erase(it);
            } 
        }
        return result;
    }
};