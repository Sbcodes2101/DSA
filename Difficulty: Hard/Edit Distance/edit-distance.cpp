class Solution {
  public:
    int solve(string& s1,string& s2,int n,int m,vector<vector<int>> &dp){
        if(n < 0) return m + 1;
        if(m < 0) return n + 1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s1[n]==s2[m]) return dp[n][m] = solve(s1,s2,n-1,m-1,dp);
        
        int insert=1+solve(s1,s2,n,m-1,dp);
        int del=1+solve(s1,s2,n-1,m,dp);
        int replace=1+solve(s1,s2,n-1,m-1,dp);
        
        return dp[n][m] = min(insert,min(del,replace));
    }
    
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(s1,s2,s1.size()-1,s2.size()-1,dp);
    }
};