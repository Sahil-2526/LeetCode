class Solution {
public:
    int t;
    vector<string> ans;

    void solve(string &num, int i, long long sum, long long mul, string expr) {
        if(i == num.size()){
            if(sum+mul == t)
                ans.push_back(expr);
            return;
        }

        long long value = 0;

        for(int j = i; j < num.size(); j++){
            if(j > i && num[i] == '0')
                break;

            value = value*10 + (num[j]-'0');
            string s = num.substr(i, j-i+1);

            if(i == 0){
                solve(num, j + 1, 0, value, s);
            }
            else{
                solve(num, j+1, sum+mul, value, expr +"+"+s);
                solve(num, j+1, sum+mul, -value, expr+"-"+s);
                solve(num, j+1, sum, mul*value,expr+"*"+s);
            }
        }
    }

    vector<string> addOperators(string num, int target){
        t = target;
        solve(num, 0, 0, 0, "");
        return ans;
    }
};