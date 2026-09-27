class Solution {
public:
    int f(int idx,int no_of_transactions,vector<int> &prices,bool buy,vector<vector<vector<int>>> &dp){
        if(idx==prices.size()) return 0;

        if(no_of_transactions==0) return 0;

        if(dp[idx][no_of_transactions][buy]!=-1) return dp[idx][no_of_transactions][buy];

        int ans = INT_MIN;
        if(buy){
            ans = max(-prices[idx]+f(idx+1,no_of_transactions,prices,false,dp),f(idx+1,no_of_transactions,prices,true,dp));
        }

        else{
            ans = max(prices[idx]+f(idx+1,no_of_transactions-1,prices,true,dp),f(idx+1,no_of_transactions,prices,false,dp));
        }

        return dp[idx][no_of_transactions][buy] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (k+1,vector<int> (2,-1)));
        return f(0,k,prices,buy,dp);
    }
};