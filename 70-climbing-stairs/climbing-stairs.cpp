class Solution {
public:
    int ans(vector<int> &dp,int n){
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int left = ans(dp,n-1);
        int right = ans(dp,n-2);
        return dp[n] = left+right;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ans(dp,n);
    }
};