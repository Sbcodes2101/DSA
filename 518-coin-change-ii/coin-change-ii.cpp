class Solution {
public:
    int f(int amount,vector<int> &coins,int idx,vector<vector<int>> &dp){
        if(idx==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(amount==0) return 1;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int not_take = f(amount,coins,idx-1,dp);
        int take = 0;
        if(amount-coins[idx]>=0){
            take = f(amount-coins[idx],coins,idx,dp);
        }

        return dp[idx][amount] = take+not_take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(amount,coins,n-1,dp);
    }
};