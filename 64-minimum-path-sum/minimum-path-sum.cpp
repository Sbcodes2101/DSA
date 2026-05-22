class Solution {
public:
    int f(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[0][0];
        }

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int left=INT_MAX;
        int up=INT_MAX;

        if(i>0) up = grid[i][j] + f(i-1,j,dp,grid);
        if(j>0) left = grid[i][j] + f(i,j-1,dp,grid);

        return dp[i][j] = min(left,up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return f(n-1,m-1,dp,grid);

        vector<int> prev(m,0);
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[j] = grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up = grid[i][j] + prev[j];
                    if(j>0) left = grid[i][j] + curr[j-1];
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};