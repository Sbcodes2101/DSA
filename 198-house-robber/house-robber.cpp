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
        vector<int> dp(n,-1);
        return f(nums,n-1,dp);
    }
};