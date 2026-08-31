class Solution {
public:
    int f(vector<int> &prices, int idx, bool buy, vector<vector<int>> &dp){
        // Change to >= to handle the +2 cooldown jump safely
        if(idx >= prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int ans = 0;

        if(buy){
            ans = max(-prices[idx] + f(prices, idx+1, false, dp), f(prices, idx+1, true, dp));
        }
        else{
             ans = max(prices[idx] + f(prices, idx+2, true, dp), f(prices, idx+1, false, dp));
        }

        return dp[idx][buy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Size it to n + 2 to safely handle index n and n + 1
        vector<vector<int>> dp(n + 2, vector<int>(2, -1));
        return f(prices, 0, true, dp);
    }
};