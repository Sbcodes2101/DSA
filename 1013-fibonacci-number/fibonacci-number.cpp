class Solution {
public:
    // recursion+memoization
    // int fibo(int n,vector<int>& dp){
    //     if(n<=1) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    //     return dp[n];
    // } 

    int fib(int n) {
        // recursion+memoization
        // vector<int> dp(n+1,-1);
        // return fibo(n,dp);

        // tabulation
        if(n<=1) return n;
        int prev2 = 0;
        int prev1 = 1; 
        int curr;   
        for(int i=2;i<=n;i++){
            curr = prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};