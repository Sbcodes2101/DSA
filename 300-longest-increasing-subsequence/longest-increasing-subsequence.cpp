class Solution {
public:
    int f(vector<int> &nums,int idx,int prev_idx,vector<vector<int>> &dp){
        if(idx==nums.size()){
            return 0;
        }

        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];

        int not_pick = f(nums,idx+1,prev_idx,dp);
        int pick = INT_MIN;
        if(prev_idx == -1 || nums[prev_idx]<nums[idx]){
            pick = 1+f(nums,idx+1,idx,dp);
        }

        return dp[idx][prev_idx+1] = max(pick,not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int> (n+1,0));
        // return f(nums,0,-1,dp);

        vector<int> dp(n,1);
        int maxlen = 1;
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