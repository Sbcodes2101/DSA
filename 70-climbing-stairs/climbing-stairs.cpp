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
        // vector<int> dp(n,0);
        // return f(n,dp);

        if(n<=2) return n;

        int prev = 2;
        int prev2 = 1;
        int curr;

        for(int i=3;i<=n;i++){
            curr = prev2+prev;
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};