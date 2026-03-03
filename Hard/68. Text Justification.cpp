class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int currCount = 0;
        int count = 0;
        int start = 0;              
        vector<string> ans;
        string s = "";
        string sa = "";
        for(int i = 0; i < n; i++) {
            if(currCount + words[i].length() + count <= maxWidth) {
                currCount += words[i].length();
                count++;
            }
            else {
                int gap = maxWidth - currCount;
                if(count == 1) {   
                    s += words[start];
                    s += string(gap, ' ');
                }
                else {
                    int k = gap / (count - 1);
                    int extra = gap % (count - 1);
                    for(int j = 0; j < count; j++) {
                        s += words[start + j];
                        if(j < count - 1) {
                            int spaces = k + (extra-- > 0 ? 1 : 0);
                            s += string(spaces, ' ');
                        }
                    }
                }
                ans.push_back(s);
                s = "";
                currCount = words[i].length();
                count = 1;
                start = i;
            }
        }
        s = "";
        for(int j = 0; j < count; j++) {
            s += words[start + j];
            if(j < count - 1) s += " ";
        }
        s += string(maxWidth - s.length(), ' ');
        ans.push_back(s);
        return ans;
    }
};