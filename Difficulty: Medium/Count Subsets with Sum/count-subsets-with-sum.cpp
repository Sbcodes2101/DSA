class Solution {
  public:
    int f(vector<int> &arr,int target,int idx,vector<vector<int>> &dp){
        if(idx==0) return (target==0);
        
        if(target<0) return 0;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        return dp[idx][target] = (f(arr,target-arr[idx-1],idx-1,dp) + f(arr,target,idx-1,dp));
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return f(arr,target,n,dp);
    //     vector<int> prev(target+1,0);
        
    //     prev[0] = 1;
    //     if(arr[0]<=target) prev[arr[0]]++;
        
    //     for(int i=1;i<n;i++){
    //         vector<int> curr(target+1,0);
    //         for(int j=0;j<=target;j++){
    //             if(j-arr[i]>=0) curr[j] = prev[j] + prev[j-arr[i]];
    //             else curr[j] = prev[j];
    //         }
    //         prev = curr;
    //     }
        
    //     return prev[target];
    }
};