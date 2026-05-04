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
    int n = val.size();
    
    vector<int> prev(W+1,0),curr(W+1,0);

    // Base case
    for(int w = wt[0]; w <= W; w++) {
        prev[w] = val[0];
    }

    for(int idx = 1; idx < n; idx++) {
        for(int w = 0; w <= W; w++) {
            int not_pick = prev[w];
            
            int pick = INT_MIN;
            if(w - wt[idx] >= 0) {
                pick = val[idx] + prev[w - wt[idx]];
            }

            curr[w] = max(pick, not_pick);
        }
        
        prev=curr;
    }
    

    return prev[W];
}
};