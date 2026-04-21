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
        int n = nums.size();
        vector<int> dp(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                    maxlen = max(maxlen,dp[i]);
                }
            }
        }

        return maxlen;
    }
};