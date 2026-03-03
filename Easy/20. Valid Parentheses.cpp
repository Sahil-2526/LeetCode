#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        st.push(-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='(') st.push(s[i]);
            else{
                if((s[i]==')'&&st.top()!='(')||(s[i]==']'&&st.top()!='[')||(s[i]=='}'&&st.top()!='{')) return false;
                else{
                    st.pop();
                    if(st.empty()) return false;
            }
          } 
        }
        return st.top()==-1? true : false;        
    } 
};