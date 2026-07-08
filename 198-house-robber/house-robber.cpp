class Solution {
public:
    int maximumhouseRob(vector<int> &nums,int i,vector<int> &dp){
        if(i==0) return nums[0];

        if(dp[i]!=-1) return dp[i];

        if(i==1) return max(nums[0],nums[1]);

        return dp[i] = max(nums[i]+maximumhouseRob(nums,i-2,dp),maximumhouseRob(nums,i-1,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return maximumhouseRob(nums,n-1,dp);
    }
};