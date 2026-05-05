class Solution {
public:
    bool f(int target,vector<int> &nums,int idx,vector<vector<int>> &dp){
        if(idx==0){
            if(target-nums[idx]==0){
                return true;
            }
            else return false;
        }

        if(dp[target][idx] != -1) return dp[target][idx];

        bool not_pick = f(target,nums,idx-1,dp);
        bool pick = 0;
        if(target-nums[idx]>=0){
            pick = f(target-nums[idx],nums,idx-1,dp);
        }
        
        return dp[target][idx]=pick+not_pick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int target = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        if(sum%2 != 0) return false;
        else{
            target = sum/2;
        }

        vector<vector<int>> dp(target+1,vector<int> (n,-1));
        return f(target,nums,n-1,dp);
    }
};