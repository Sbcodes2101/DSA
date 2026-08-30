class Solution {
  public:
    
    bool f(vector<int> &arr,int target,int idx,vector<vector<int>> &dp){
        if(idx<0) return (target==0);
        
        if(target<0) return false;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        return dp[idx][target] = f(arr,target-arr[idx],idx-1,dp)+f(arr,target,idx-1,dp);
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
        
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        
        return f(arr,target,n-1,dp);
    }
};