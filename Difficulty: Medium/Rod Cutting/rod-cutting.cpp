class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1,0);
        
        for(int i=0;i<n;i++){
            dp[i+1] = price[i];
        }
        
        int maxSum = INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=i;j>=0;j--){
                dp[i] = max(dp[i],dp[j]+dp[i-j]);
                maxSum = max(maxSum,dp[i]);
            }
        }
        
        return maxSum;
    }
};