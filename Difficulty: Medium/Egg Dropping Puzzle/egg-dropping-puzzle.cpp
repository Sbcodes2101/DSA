class Solution {
  public:
    // int findMinimum(int eggs,int floors,vector<vector<int>> &dp){
    //     if(eggs==1) return floors;
        
    //     if(floors==0) return 0;
        
    //     if(dp[eggs][floors]!=-1) return dp[eggs][floors];
        
    //     int result = INT_MAX;
        
    //     for(int i=1;i<=floors;i++){
    //         int ans = 1+max(findMinimum(eggs-1,i-1,dp),findMinimum(eggs,floors-i,dp));
    //         result = min(ans,result);
    //     }
        
    //     return dp[eggs][floors] = result;
    // }
    
    int findMinimum(int eggs,int moves,vector<vector<int>> &dp){
        if(eggs ==0 || moves == 0) return 0;
        
        if(eggs==1) return moves;
        
        if(dp[eggs][moves]!=-1) return dp[eggs][moves];
        
        return dp[eggs][moves] = 1+findMinimum(eggs-1,moves-1,dp)+findMinimum(eggs,moves-1,dp);
    }
    
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        
        int moves=0;
        while(findMinimum(n,moves,dp)<k){
            moves++;
        }
        
        return moves;
    }
};