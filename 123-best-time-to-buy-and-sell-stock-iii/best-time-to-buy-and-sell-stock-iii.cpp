class Solution {
public:
    int f(int idx,vector<int> &prices,bool buy,int no_of_transactions,vector<vector<vector<int>>> &dp){
        if(idx==prices.size() || no_of_transactions==0){
            return 0;
        }

        if(dp[idx][buy][no_of_transactions]!=-1) return dp[idx][buy][no_of_transactions];

        if(buy){
            int profit = -prices[idx] + f(idx+1,prices,false,no_of_transactions,dp);
            int not_pick = f(idx+1,prices,true,no_of_transactions,dp);

            return dp[idx][buy][no_of_transactions] = max(profit,not_pick);
        }

        else{
            int profit = prices[idx] + f(idx+1,prices,true,no_of_transactions-1,dp);
            int not_pick = f(idx+1,prices,false,no_of_transactions,dp);

            return dp[idx][buy][no_of_transactions] = max(profit,not_pick);
        }
    }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // bool buy = true;

        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
        // // return f(0,prices,buy,2,dp);

        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         for(int k=1;k<=2;k++){
        //             if(j==1){
        //                 dp[i][j][k] = max(-prices[i] + dp[i+1][0][k],dp[i+1][1][k]);
        //             }
        //             else{
        //                 dp[i][j][k] = max(prices[i] + dp[i+1][1][k-1],dp[i+1][0][k]);
        //             }
        //         }
        //     }
        // }

        // return dp[0][1][2];

         int n = prices.size();

        vector<vector<int>> prev(2,vector<int> (3,0));

        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int> (3,0));
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==1){
                        curr[j][k] = max(-prices[i] + prev[0][k],prev[1][k]);
                    }
                    else{
                        curr[j][k] = max(prices[i] + prev[1][k-1],prev[0][k]);
                    }
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
};