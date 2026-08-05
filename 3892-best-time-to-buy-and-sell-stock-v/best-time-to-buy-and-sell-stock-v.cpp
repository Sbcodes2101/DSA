class Solution {
public:
    const long long NEG = -1e18;
    long long maxProfit(int index,int buy,vector<int> &prices,int transaction,vector<vector<vector<long long>>> &dp){
        if(transaction == 0){
    return 0;
}

if(index == prices.size()){
    return (buy == 1) ? NEG : 0;
}

        long long ans = NEG;

        if(dp[index][buy][transaction]!=-1) return dp[index][buy][transaction];

        if(buy==2){
            // either we do not buy the stock or we buy or we shortsell
            ans = max(maxProfit(index+1,2,prices,transaction,dp),max(-1LL*prices[index]+maxProfit(index+1,0,prices,transaction,dp),1LL*prices[index]+maxProfit(index+1,1,prices,transaction,dp)));
        }

        if(buy==1){
            // either we shortbuy or we do not shortbuy
            ans = max(maxProfit(index+1,1,prices,transaction,dp),-1LL*prices[index] + maxProfit(index+1,2,prices,transaction-1,dp));
        }

        if(buy==0){
            // either we sell it or we dont sell it
            ans = max(maxProfit(index+1,0,prices,transaction,dp),1LL*prices[index]+maxProfit(index+1,2,prices,transaction-1,dp));
        }

        return  dp[index][buy][transaction] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(4,vector<long long> (k+1,-1)));
        return maxProfit(0,2,prices,k,dp);
    }
};