class Solution {
public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(n,vector<bool> (m,false));
        vector<vector<bool>> atlantic(n,vector<bool> (m,false));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
        pacific[i][0] = true;
         q.push({i, 0});
        }

        while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
            for(int d = 0; d < 4; d++){
            int nr = r + row[d];
            int nc = c + col[d];
                if(isValid(nr, nc, n, m) && !pacific[nr][nc] && heights[nr][nc] >= heights[r][c]){
                pacific[nr][nc] = true;
                q.push({nr, nc});
                }
            }
        }
        
        for(int i=0;i<m;i++){
            pacific[0][i] = true;
            q.push({0,i});
        }

        while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr = r+row[i];
                    int nc = c+col[i];

                    if(isValid(nr,nc,n,m) && !pacific[nr][nc] && heights[nr][nc]>=heights[r][c]){
                        pacific[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }


        for(int i=0;i<m;i++){
            atlantic[n-1][i] = true;
            q.push({n-1,i});
        }

        while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr = r+row[i];
                    int nc = c+col[i];

                    if(isValid(nr,nc,n,m) && !atlantic[nr][nc] && heights[nr][nc]>=heights[r][c]){
                        atlantic[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }

        for(int i=0;i<n;i++){
            atlantic[i][m-1] = true;
            q.push({i,m-1});
        }

        while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nr = r+row[i];
                    int nc = c+col[i];

                    if(isValid(nr,nc,n,m) && !atlantic[nr][nc] && heights[nr][nc]>=heights[r][c]){
                        atlantic[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==true && atlantic[i][j]==true){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};