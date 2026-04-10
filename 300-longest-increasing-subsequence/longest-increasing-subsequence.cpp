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
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        // return f(0,-1,nums,dp);

        for(int idx=nums.size()-1; idx>=0; idx--){
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
                int len = dp[idx+1][prev_idx+1];
                if(prev_idx == -1 || nums[idx]>nums[prev_idx]){
                    len = max(len,1+dp[idx+1][idx+1]);
                }
                dp[idx][prev_idx+1] = len;
            }
        }

        return dp[0][0];
    }
};