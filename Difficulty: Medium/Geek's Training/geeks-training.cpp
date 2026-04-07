class Solution {
  public:
    int f(int days,int last,vector<vector<int>> &mat,vector<vector<int>> &dp){
        int n=mat.size();
        if(days==0){
            int maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi = max(maxi,mat[0][i]);
                }
            }
            return maxi;
        }
        
        if(dp[days][last]!=-1) return dp[days][last];
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last)
           {
            int points = mat[days][i] + f(days-1,i,mat,dp);
            maxi = max(points,maxi);
           }
        }
        
        return dp[days][last] = maxi;
    }
    
    
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return f(n-1,3,mat,dp);
    }
};