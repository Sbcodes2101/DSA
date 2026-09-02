class Solution {
public:
    int f(vector<vector<int>> &matrix,int row,int col,int size,vector<vector<int>> &dp){
        if(col<0 || col>size) return 1e9;

        if(row==size) return dp[row][col] = matrix[row][col];

        if(dp[row][col]!=1e9) return dp[row][col];

        return dp[row][col] = matrix[row][col]+min(f(matrix,row+1,col,size,dp),min(f(matrix,row+1,col+1,size,dp),f(matrix,row+1,col-1,size,dp)));
        
        
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,1e9));
        int ans = 1e9;
        
        for(int i=0;i<n;i++){
            ans = min(ans,f(matrix,0,i,matrix.size()-1,dp));
        }
        
        return ans;
    }
};