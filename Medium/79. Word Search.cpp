class Solution {
public:
    int m, n;

    bool find(int i, int j, int k, vector<vector<char>>& board, string& word) {
        if (k == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[k]) return false;
        char temp = board[i][j];
        board[i][j] = '.';
        bool t = find(i- 1, j, k+1, board, word);
        bool l = find(i, j-1, k+1, board, word);
        bool r = find(i, j+1, k+1, board, word);
        bool b = find(i+1, j, k+1, board, word);
        board[i][j] = temp;
        return t || l || r || b;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (find(i, j, 0, board, word)) return true;
                }
            }
        }

        return false;
    }
};