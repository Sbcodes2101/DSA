class Solution {
public:
    int f(int amount,vector<int>& coins,int idx,vector<vector<int>> &dp){
        if(amount == 0) return 1;

        if(idx<0 || amount<0) return 0;

        if(dp[idx][amount]!=-1) return dp[idx][amount];
    
        int not_pick = f(amount,coins,idx-1,dp);
        int pick = 0;
        if(idx-1>=0) pick = f(amount-coins[idx-1],coins,idx,dp);

        return dp[idx][amount] = pick+not_pick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int> (amount+1,0));

        for(int i=0;i<=n;i++){
            dp[i][0] = 1; 
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j] = dp[i-1][j];
                if(j-coins[i-1]>=0) dp[i][j] += dp[i][j-coins[i-1]];
            }
        }

        return dp[n][amount];
    }
};