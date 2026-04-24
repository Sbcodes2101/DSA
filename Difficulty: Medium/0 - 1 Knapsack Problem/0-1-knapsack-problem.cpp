class Solution {
  public:
    int solve(int W,vector<int> &val,vector<int> &wt,int idx,vector<vector<int>> &dp){
        if(idx==0){
            if(W-wt[0]>=0){
                return val[0];
            }
            else return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int pick = INT_MIN;
        if(W-wt[idx]>=0){
            pick = val[idx]+solve(W-wt[idx],val,wt,idx-1,dp);
        }
        int not_pick = solve(W,val,wt,idx-1,dp);
        
        return dp[idx][W] = max(pick,not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n,vector<int> (W+1,-1));
        return solve(W,val,wt,n-1,dp);
    }
};