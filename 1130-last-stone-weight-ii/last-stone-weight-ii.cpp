class Solution {
public:
    int f(vector<int> &stones,int sum1,int target,int idx,vector<vector<int>> &dp){
        if(idx==0){
            int sum2=target-sum1;
            return abs(sum1-sum2);
        }

        if(dp[idx][sum1]!=-1) return dp[idx][sum1];

        int pick = f(stones,sum1+stones[idx-1],target,idx-1,dp);
        int not_pick = f(stones,sum1,target,idx-1,dp);

        return dp[idx][sum1] = min(pick,not_pick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += stones[i];
        }

        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return f(stones,0,sum,n,dp);
    }
};