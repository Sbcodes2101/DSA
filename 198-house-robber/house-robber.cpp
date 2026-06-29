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
        // return f(nums,n-1,dp);
        int prev2 = 0;
        int prev = nums[0];
        int curr;
        if(nums.size()==1) return nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick+=prev2;
            int not_pick = prev;

            curr = max(pick,not_pick);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};