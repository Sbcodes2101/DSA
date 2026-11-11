class Solution {
public:
    int solve(vector<int> &costs,int steps,vector<int> &dp){
        int n = costs.size(); 
        if(steps==n) return 0;
        if(steps>n) return INT_MAX;

        if(dp[steps]!=-1) return dp[steps];

        int ans = INT_MAX;

        if(steps+1<=n){
            int res = solve(costs,steps+1,dp);
            if(res != INT_MAX){
                ans = min(ans,costs[steps] + 1 + res);
            }
        }

        if(steps+2<=n){
            int res1 = solve(costs,steps+2,dp);
            if(res1 != INT_MAX){
                ans = min(ans,costs[steps+1] + 4 + res1);
            }
        }

        if(steps+3<=n){
            int res2 = solve(costs,steps+3,dp);
            if(res2!=INT_MAX){
                ans = min(ans,costs[steps+2] + 9 + res2);
            }
        }


        return dp[steps] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return solve(costs,0,dp);
    }
};