class Solution {
public:
    int f(vector<int> &nums,vector<int> &dp,int idx){
        if(idx==0) return nums[0];
        if(idx<0) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int pick = nums[idx] + f(nums,dp,idx-2);
        int not_pick = f(nums,dp,idx-1);

        return dp[idx] = max(pick,not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,dp,n-1);
    }
};