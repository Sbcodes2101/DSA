class Solution {
  public:
    int f(vector<int>& arr,int idx,int sum1,int target,vector<vector<int>> &dp){
        if(idx==0){
            int sum2 = target-sum1;
            return abs(sum1-sum2);
        }
        
        if(dp[idx][sum1]!=-1) return dp[idx][sum1];
        
        int pick1 = f(arr,idx-1,sum1+arr[idx-1],target,dp);
        int pick2 = f(arr,idx-1,sum1,target,dp);
        
        return dp[idx][sum1] = min(pick1,pick2);
    }
    
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return f(arr,n,0,sum,dp);
    }
};
