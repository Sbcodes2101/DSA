class Solution {
public:
    int f(vector<int> &coins,int amount,int idx,vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }

        if(idx==0 || amount<0) return 1e9;

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        return dp[idx][amount] = min(f(coins,amount,idx-1,dp),1+f(coins,amount-coins[idx-1],idx,dp));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        int ans = f(coins,amount,n,dp);
        return (ans==1e9)? -1:ans;
    }
};