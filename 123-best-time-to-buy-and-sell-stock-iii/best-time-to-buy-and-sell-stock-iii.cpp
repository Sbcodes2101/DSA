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
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return f(prices,0,2,true,dp);
    }
};