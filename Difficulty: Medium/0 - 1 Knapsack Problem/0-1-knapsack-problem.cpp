class Solution {
  public:
    int f(int W,vector<int> &val,vector<int> &wt,int idx,vector<vector<int>> &dp){
        int ans = INT_MIN;
        
        if(idx == val.size()){
            return (ans==INT_MIN)? 0:ans;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int pick = 0;
        if(W-wt[idx]>=0) pick = val[idx]+f(W-wt[idx],val,wt,idx+1,dp);
        int not_pick = f(W,val,wt,idx+1,dp);
        
        dp[idx][W] = max(pick,not_pick);
        
        return ans = max(pick,not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n,vector<int> (W+1,-1));
        return f(W,val,wt,0,dp);
    }
};