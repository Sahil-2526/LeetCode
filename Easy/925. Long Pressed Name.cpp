#include <iostream>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i++; 
            } 
            else if (j == 0 || typed[j] != typed[j - 1]) {
                return false;  
            }
            j++;
        }

        return i == name.size();
    }
};

// we compare characters of name and typed. If they match, we move to the next character in name. If they don't match, we check if the current character in typed is the same as the previous character (indicating a long press). If it's not a long press, we return false. Finally, we check if we've matched all characters in name.