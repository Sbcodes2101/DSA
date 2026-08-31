class Solution {
public:
    int f(vector<int> &prices, int idx, bool buy, vector<vector<int>> &dp, int fee){
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int ans = 0;

        if(buy){
            
            ans = max(-prices[idx] + f(prices, idx + 1, false, dp, fee), 
                      f(prices, idx + 1, true, dp, fee));
        }
        else{
           
            ans = max(prices[idx] + f(prices, idx + 1, true, dp, fee) - fee, 
                      f(prices, idx + 1, false, dp, fee));
        }

        return dp[idx][buy] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
     
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, true, dp, fee);
    }
};