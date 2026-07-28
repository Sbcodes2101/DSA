class Solution {
public:
    int findTotalSum(vector<int> &nums,int target,int idx,vector<vector<int>> &dp){
        if(target==0){
            return 1;
        }

        if(target<0 || idx<0) return 0;

        if(dp[idx][target]!=-1) return dp[idx][target];

        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans += findTotalSum(nums,target-nums[i],i,dp);
        }

        return dp[idx][target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return findTotalSum(nums,target,n,dp);
    }
};