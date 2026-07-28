class Solution {
public:
    int findTotalSum(vector<int> &nums,int target,int idx,vector<int> &dp){
        if(target==0){
            return 1;
        }

        if(target<0) return 0;

        if(dp[target]!=-1) return dp[target];

        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans += findTotalSum(nums,target-nums[i],idx,dp);
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return findTotalSum(nums,target,n,dp);
    }
};