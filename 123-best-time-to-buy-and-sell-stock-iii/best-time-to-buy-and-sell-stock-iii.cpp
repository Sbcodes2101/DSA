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
        int n = prices.size();
        bool buy = true;

        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return f(0,prices,buy,2,dp);
    }
};