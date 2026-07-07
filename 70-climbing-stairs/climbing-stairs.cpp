class Solution {
public:
    int f(int n,vector<int> &dp){
        if(n==1 || n==2) return n;

        if(dp[n]!=-1) return dp[n];

        int one = f(n-1,dp);
        int two = f(n-2,dp);
        
        return dp[n] = one+two;

    }

    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        // return f(n,dp);

        if(n<=1) return n;
        dp[2] = 2;
        dp[1] = 1;

        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};