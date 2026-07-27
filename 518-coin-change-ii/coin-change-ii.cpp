class Solution {
public:
    int f(int amount,vector<int> &coins,int idx,vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }

        if(amount<0 || idx==0) return 0; 

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int pick = 0;
        if(amount-coins[idx-1]>=0) pick = f(amount-coins[idx-1],coins,idx,dp);
        int not_pick = f(amount,coins,idx-1,dp);

        return dp[idx][amount] = pick+not_pick;
    } 


    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        return f(amount,coins,n,dp);


    }
};