class Solution {
public:
    string trim(string s) {
        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') i++;
        return s.substr(i);
    }
    bool isSmaller(string a, string b) {
        a = trim(a);
        b = trim(b);
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }
    string subtract(string a, string b) {
        string result = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++) {
            int digitA = a[i] - '0';
            int digitB = (i < b.size()) ? b[i] - '0' : 0;
            int sub = digitA - digitB - carry;
            if (sub < 0) {
                sub += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result += (sub + '0');
        }
        
        reverse(result.begin(), result.end());
        return trim(result);
    }

    int divide(int dividend, int divisor) {
        // if (divisor == 0) return INT_MAX;
        // if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool negative = (dividend< 0)^(divisor<0);
        string a = to_string(dividend);
        string b = to_string(divisor);
        if (a[0] == '-') a = a.substr(1);
        if (b[0] == '-') b = b.substr(1);
        string result = "";
        string current = "";
        for (int i=0;i<a.size();i++) {
            current += a[i];
            current = trim(current);
            int count = 0;
            while (!isSmaller(current, b)) {
                current = subtract(current, b);
                count++;
            }
            result += (count + '0');
        }
        result = trim(result);
        if (result == "") result = "0";
        long long ans = stoll(result);
        if (negative) ans = -ans;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};