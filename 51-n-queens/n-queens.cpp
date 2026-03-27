class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board){
        int n=board.size();
        int duprow = row;
        int dupcol = col;

        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

         row = duprow;
         col = dupcol;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;col--;
        }

         row = duprow;
         col = dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;col--;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(i,col,board)){
                board[i][col] = 'Q';
                solve(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }

        solve(0,board,ans,n);
        return ans;
    }
};