class Solution {
public:
    bool isValid(int i,int j,int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p;
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        p.push({grid[0][0],{0,0}});
        int time=INT_MIN;

        while(!p.empty()){
            int currTime = p.top().first;
            int r = p.top().second.first;
            int c = p.top().second.second;
            p.pop();

            if(visited[r][c]==true) continue;

            visited[r][c] = true;

            if(r == n-1 && c == n-1){
                return currTime;
            }

            int row[4] = {-1,1,0,0};
            int col[4] = {0,0,-1,1};

            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];

                if(isValid(nr,nc,n) && !visited[nr][nc]){
                    int newTime = max(currTime,grid[nr][nc]);
                    p.push({newTime,{nr,nc}});
                }
            }
        }

        return -1;
    }
};