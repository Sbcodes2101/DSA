class Solution {
public:
    int maximumProfit(vector<int>& prices,int index,bool buy,int no_of_transaction,vector<vector<vector<int>>> &dp){
        if(index==prices.size() || no_of_transaction == 0){
            return 0;
        }

        if(buy){
            return dp[index][buy][no_of_transaction] = max(maximumProfit(prices,index+1,true,no_of_transaction,dp),-prices[index]+maximumProfit(prices,index+1,false,no_of_transaction,dp));
        }

        else{
            return dp[index][buy][no_of_transaction] = max(maximumProfit(prices,index+1,false,no_of_transaction,dp),prices[index]+maximumProfit(prices,index+1,true,no_of_transaction-1,dp));
        }

        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (3,vector<int> (2,0)));
        // return maximumProfit(prices,0,true,2,dp);

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                for(int k=0;k<=1;k++){
                    if(k==1){
                        dp[i][j][k] = max(dp[i+1][j][1],-prices[i]+dp[i+1][j][0]);
                    }
                    else{
                        if(j>0) dp[i][j][k] = max(dp[i+1][j][0],prices[i]+dp[i+1][j-1][1]);
                    }
                }
            }
        }

        return dp[0][2][1];
    }
};