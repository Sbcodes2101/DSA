class Solution {
public:
    int rows[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int n;int m;
    bool isVald(int i,int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int i=0;i<4;i++){
                            int nr = r + rows[i];
                            int nc = c + col[i];

                            if(isVald(nr,nc) && !visited[nr][nc] && grid[nr][nc] == '1'){
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