class Solution {
  public:
    int f(int W,vector<int> &val,vector<int> &wt,int idx,vector<vector<int>> &dp){
        if(idx==0){
            if(W-wt[0]>=0){
                return val[0];
            }
            else return 0;
        }
        
        if(dp[W][idx]!=-1) return dp[W][idx];
        
        int pick=INT_MIN;
        
        if(W-wt[idx]>=0){
            pick = val[idx] + f(W-wt[idx],val,wt,idx-1,dp);
        }
        
        int not_pick = f(W,val,wt,idx-1,dp);
        
        return dp[W][idx]=max(pick,not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
        return f(W,val,wt,n-1,dp);
    }
};