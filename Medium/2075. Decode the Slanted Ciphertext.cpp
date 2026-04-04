class Solution {
public:
    string decodeCiphertext(string encodedText, int rows){
        int n = encodedText.size();
        int cols = n / rows;

        int i = 0, j = 0;
        string txt = "";
        int val = 1;

        while (j < cols) {
            int idx = i * cols + j;   
            txt += encodedText[idx];

            if (i == rows - 1 || j == cols - 1) {   
                i = 0;
                j = val;
                val++;
            } else {
                i++;
                j++;
            }
        }

        while (!txt.empty() && txt.back() == ' ') {
            txt.pop_back();
        }

        return txt;   
    }
};