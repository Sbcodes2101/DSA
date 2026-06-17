class Solution {
public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][m-1] == 'O') q.push({i,m-1});
        }

        for(int i=0;i<m;i++){
            if(board[0][i] == 'O') q.push({0,i});
            if(board[n-1][i] == 'O') q.push({n-1,i});
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            board[r][c] = 'S';
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];

                if(isValid(nr,nc,n,m) && board[nr][nc]=='O'){
                    board[nr][nc] = 'S';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='S') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};