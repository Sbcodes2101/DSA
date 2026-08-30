class Solution {
  public:
    
    bool f(vector<int> &arr,int target,int idx,vector<vector<int>> &dp){
        if(idx==0) return (target==0);
        
        if(target<0) return false;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        return dp[idx][target] = f(arr,target-arr[idx-1],idx-1,dp)+f(arr,target,idx-1,dp);
    }
    
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        if(sum%2 != 0) return false;
        
        int target = sum/2;
        
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        
        // return f(arr,target,n,dp);
        
        dp[0][0] = 1;
        
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1]) dp[i][j] += dp[i-1][j-arr[i-1]];
            }
        }
        
        return dp[n][target];
    }
};