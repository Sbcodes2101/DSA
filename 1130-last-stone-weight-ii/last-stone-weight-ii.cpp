class Solution {
public:
    int f(vector<int>& stones,int idx,int sum,int target,vector<vector<int>> &dp){
        if(idx==stones.size()){
            int sum2 = target-sum;
            return dp[idx][sum] = abs(sum2-sum);
        }

        if(dp[idx][sum]!=-1) return dp[idx][sum];

        return dp[idx][sum] = min(f(stones,idx+1,sum+stones[idx],target,dp),f(stones,idx+1,sum,target,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int target = 0;

        for(int i=0;i<n;i++){
            target += stones[i];
        }

        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return f(stones,0,0,target,dp);
    }
};