class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        
        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<n;i++){
            int one = cost[i]+dp[i-1];
            int two = cost[i]+dp[i-2];

            dp[i] = min(one,two);
        }

        return min(dp[n-1],dp[n-2]);
    }
};