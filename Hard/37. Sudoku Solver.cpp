class Solution { 
public: 
    bool isValid(int r, int c, int val, vector<vector<char>>& board){ 
        for(int i=0; i<9; i++){ 
            if(board[r][i] == val+'0' || board[i][c] == val+'0') return false; 
        } 
        int br = r/3; 
        int bc = c/3; 
        for(int i=br*3; i<br*3+3; i++){ 
            for(int j=bc*3; j<bc*3+3; j++){ 
                if(board[i][j] == val+'0') return false; 
            } 
        } 
        return true; 
    } 
    bool solve(int r, int c, vector<vector<char>>& board){ 
        int idx = r*9+c; 
        if(idx == 81) return true; 
        if(board[r][c] == '.'){ 
            for(int i=1; i<=9; i++){ 
                if(isValid(r, c, i, board)){ 
                    board[r][c] = '0'+i; 
                    if(solve((idx+1)/9, (idx+1)%9, board)) return true; 
                    board[r][c] = '.'; 
                } 
            } 
            return false; 
        } 
        else{ 
            return solve((idx+1)/9, (idx+1)%9, board); 
        } 
    } 
    void solveSudoku(vector<vector<char>>& board) { 
        solve(0, 0, board); 
    } 
};