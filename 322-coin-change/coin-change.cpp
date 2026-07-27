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
        // int n = coins.size();
        // vector<vector<int>> dp(n+1,vector<int> (amount+1,0));
        // // int ans = f(coins,amount,n,dp);
        // // return (ans==1e9)? -1:ans;

        // for(int i=0;i<=n;i++){
        //     dp[i][0] = 0;
        // }

        // for(int i=0;i<=amount;i++){
        //     dp[0][i] = 1e9;
        // }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=amount;j++){
        //         int pick=1e9;
        //         if(j-coins[i-1]>=0) pick = 1+dp[i][j-coins[i-1]];
        //         int not_pick = dp[i-1][j];
        //         dp[i][j] = min(pick,not_pick);
        //     }
        // }

        // return (dp[n][amount]==1e9)? -1:dp[n][amount];

        int n = coins.size();
        vector<int> curr(amount+1,1e9);

        curr[0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int pick = 1e9;
                if(j-coins[i-1]>=0) pick = 1+curr[j-coins[i-1]];
                int not_pick = curr[j];
                curr[j] = min(pick,not_pick);
            }
        }

        return (curr[amount]==1e9)? -1:curr[amount];
    }
};