class Solution {
  public:
    int f(int idx,vector<int>& arr,int sum,int target,vector<vector<int>> &dp){
        if(idx==0){
            int sum1 = target-sum;
            return abs(sum-sum1);
        }
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        return dp[idx][sum] = min(f(idx-1,arr,sum+arr[idx-1],target,dp),f(idx-1,arr,sum,target,dp));
    }
    
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        
        return f(n,arr,0,sum,dp);
    }
};
