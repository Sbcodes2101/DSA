class Solution {
public:
    int f(vector<int> &nums,int idx,vector<int> &dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int pick = nums[idx]+f(nums,idx-2,dp);
        int not_pick = f(nums,idx-1,dp);

        return dp[idx]=max(pick,not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        // return f(nums,n-1,dp);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2;i<=n;i++){
            int pick = nums[i-1]+dp[i-2];
            int not_pick = dp[i-1];

            dp[i] = max(pick,not_pick);
        }
        return dp[n];
    }
};