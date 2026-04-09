class Solution {
public:
    int f(int idx,int prev_idx,vector<int> &nums,vector<vector<int>> &dp){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        int pick = INT_MIN;
        int notpick = 0+f(idx+1,prev_idx,nums,dp);
        if(prev_idx == -1 || nums[idx]>nums[prev_idx]){
            pick = 1+f(idx+1,idx,nums,dp);
        }

        return dp[idx][prev_idx+1]=max(pick,notpick);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};