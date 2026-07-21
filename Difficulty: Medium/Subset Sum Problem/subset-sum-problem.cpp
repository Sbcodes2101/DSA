class Solution {
  public:
    bool f(vector<int> &arr,int target,int idx,vector<vector<int>> &dp){
        if(idx==0) return (target==arr[idx]);
        
        if(target<0) return 0;
        
        if(arr[idx]==target) return 1;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        return dp[idx][target] = (f(arr,target-arr[idx],idx-1,dp) || f(arr,target,idx-1,dp));
        
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return f(arr,sum,n-1,dp);
    }
};