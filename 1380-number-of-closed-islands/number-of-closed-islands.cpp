class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1}; 

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 &&  (i==0 || j==0 || i==n-1 || j==m-1)){

                    q.push({i,j});
                    visited[i][j] = 1;

                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nr = r+row[k];
                            int nc = c+col[k];

                            if(isValid(nr,nc,n,m) && grid[nr][nc] == 0 && !visited[nr][nc]){
                                visited[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    ans++;
                    q.push({i,j});
                    visited[i][j] = 1;

                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nr = r+row[k];
                            int nc = c+col[k];

                            if(isValid(nr,nc,n,m) && grid[nr][nc]==0 && !visited[nr][nc]){
                                visited[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        return ans;
        
    }
};