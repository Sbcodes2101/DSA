class Solution {
public:
    int f(vector<int> &prices,int idx,int no_of_transaction,bool buy,vector<vector<vector<int>>> &dp){
        if(idx==prices.size()) return 0;

        if(no_of_transaction == 0) return 0;

        if(dp[idx][buy][no_of_transaction] != -1) return dp[idx][buy][no_of_transaction];

        int ans=0;

        if(buy){
            ans += max(-prices[idx]+f(prices,idx+1,no_of_transaction,false,dp),f(prices,idx+1,no_of_transaction,true,dp));
        }

        else{
            ans += max(prices[idx]+f(prices,idx+1,no_of_transaction-1,true,dp),f(prices,idx+1,no_of_transaction,false,dp));
        }

        return dp[idx][buy][no_of_transaction] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        // return f(prices,0,2,true,dp);

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    if(j==1){
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else{
                        if(k>0) dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};