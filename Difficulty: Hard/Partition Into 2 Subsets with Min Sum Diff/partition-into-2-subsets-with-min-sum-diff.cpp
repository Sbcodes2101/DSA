class Solution {
  public:
    int f(vector<int>& arr,int idx,int &ans,int sum1,int target, vector<vector<int>> &dp){
        if(idx==0){
            int sum2 = target-sum1;
            return abs(sum2-sum1);
        }
        
        if(dp[idx][sum1]!=-1) return dp[idx][sum1];
        
        return dp[idx][sum1] = min(f(arr,idx-1,ans,sum1+arr[idx-1],target,dp),f(arr,idx-1,ans,sum1,target,dp));
        
    }
    
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        int sum =0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        
        return f(arr,n,ans,0,sum,dp);
        
    }
};
