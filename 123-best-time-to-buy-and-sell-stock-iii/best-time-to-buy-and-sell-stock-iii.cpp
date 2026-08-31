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
        vector<vector<int>> prev(2,vector<int> (3,0));

        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int> (3,0));
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    if(j==1){
                        curr[j][k] = max(-prices[i]+prev[0][k],prev[1][k]);
                    }
                    else{
                        if(k>0) curr[j][k] = max(prices[i]+prev[1][k-1],prev[0][k]);
                    }
                }
            }
            prev = curr;
        }

        return prev[1][2];
    }
};