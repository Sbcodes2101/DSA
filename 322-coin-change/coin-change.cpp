class Solution {
public:
    int f(vector<int> &coins,int target,int idx,vector<vector<int>> &dp){
        if(target==0) return 0;

        if(idx<0) return INT_MAX;

        if(dp[idx][target]!=-1) return dp[idx][target];


        int pick = INT_MAX;
        if (target >= coins[idx]) {
            int res = f(coins, target - coins[idx], idx,dp);
            if (res != INT_MAX)
            pick = 1 + res;
        }

        int not_pick = f(coins,target,idx-1,dp);

        return dp[idx][target] = min(pick,not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
       int ans = f(coins,amount,n-1,dp);
       return (ans==INT_MAX)? -1:ans;
    }
};