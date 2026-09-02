class Solution {
  public:
    int f(vector<vector<int>> &mat,int row,int col,vector<vector<int>> &dp,int r,int c){
        if(col<0 || col>=c) return -1e9;
        
        if(row==r-1) return mat[row][col];
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        return dp[row][col] = mat[row][col]+max(f(mat,row+1,col,dp,r,c),max(f(mat,row+1,col+1,dp,r,c),f(mat,row+1,col-1,dp,r,c)));
    }
    
    
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans = INT_MIN;
        
        for(int i=0;i<m;i++){
            ans = max(ans,f(mat,0,i,dp,n,m));
        }
        
        return ans;
    }
};