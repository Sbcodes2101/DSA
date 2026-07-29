class Solution {
  public:
    int f(int W,vector<int> &val,vector<int> &wt,int idx,vector<vector<int>> &dp){
        if(idx == 0){
            return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int pick = 0;
        if(W-wt[idx-1]>=0) pick = val[idx-1]+f(W-wt[idx-1],val,wt,idx-1,dp);
        int not_pick = f(W,val,wt,idx-1,dp);
        
        
        return dp[idx][W] = max(pick,not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        // vector<vector<int>> dp(n+1,vector<int> (W+1,0));
        // // return f(W,val,wt,n,dp);
        
        
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=W;j++){
        //         int pick = 0;
        //         if(j-wt[i-1]>=0) pick = val[i-1]+dp[i-1][j-wt[i-1]];
        //         int not_pick = dp[i-1][j];
        //         dp[i][j] = max(pick,not_pick);
        //     }
        // }
        
        
        // return dp[n][W];
        
        // vector<int> prev(W+1,0);
        
        // for(int i=1;i<=n;i++){
        //     vector<int> curr(W+1,0);
        //     for(int j=0;j<=W;j++){
        //         int pick = 0;
        //         if(j-wt[i-1]>=0) pick = val[i-1]+prev[j-wt[i-1]];
        //         int not_pick = prev[j];
        //         curr[j] = max(pick,not_pick);
        //     }
            
        //     prev = curr;
        // }
        
        // return prev[W];
        
        
        vector<int> curr(W+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=W;j>=0;j--){
                int pick = 0;
                if(j-wt[i-1]>=0) pick = val[i-1]+curr[j-wt[i-1]];
                int not_pick = curr[j];
                curr[j] = max(pick,not_pick);
            }
        }
        
        return curr[W];
    }
};