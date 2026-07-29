class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        
        vector<int> dp(n+1,0);
        
        if(n==1) return price[0];
        
        for(int i=1;i<=n;i++){
            dp[i] = price[i-1];
        }
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] = max(dp[i],dp[j]+dp[i-j]);
            }
        }
        
        return dp[n];
    }
};