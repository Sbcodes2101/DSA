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
        // vector<vector<double>> dp(n+1,vector<double> (amount+1,0));
        // return f(amount,coins,n,dp);
        
        // for(int i=0;i<=n;i++){
        //     dp[i][0] = 1;
        // }

        vector<double> prev(amount+1,0);
        prev[0] = 1;

        for(double i=1;i<=n;i++){
            vector<double> curr(amount+1,0);
            curr[0]=1;
            for(double j=1;j<=amount;j++){
                if(j-coins[i-1]>=0) curr[j] = prev[j]+curr[j-coins[i-1]];
                else curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[amount];
    }
};