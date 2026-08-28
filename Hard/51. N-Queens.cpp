class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<int>& board, int r, int c){
        for(int i=0; i<r; i++){
            if(board[i] == c || abs(board[i]-c) == abs(i-r)) return false;
        }
        return true;
    }
    void solve(int r, vector<int>& board){
        if(r == board.size()){
            vector<string> ans;
            for(int i=0; i<r; i++){
                string s = "";
                for(int j=0; j<r; j++){
                    if(board[i] == j) s+='Q';
                    else s+='.';
                }
                ans.push_back(s);
            }
            res.push_back(ans);
        }
        for(int c=0; c<board.size(); c++){
            if(isSafe(board, r, c)){
                board[r] = c;
                solve(r+1, board);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n, 0);
        solve(0, board);
        return res;        
    }
};