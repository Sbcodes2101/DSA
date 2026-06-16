class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 &&j<m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int timer = -1;
        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh==0) return 0;

        while(!q.empty()){
            timer++;
            int size = q.size();

            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};

            while(size--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr = r+row[i];
                    int nc = c+col[i];

                    if(isValid(nr,nc,n,m) && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return timer;
    }
};