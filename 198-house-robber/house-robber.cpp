class Solution {
public:
    // Memoization
    // int f(int idx,vector<int> &nums,vector<int> &dp){
    //     if(idx==0) return nums[idx];
    //     if(idx<0) return 0;
    //     if(dp[idx]!=-1) return dp[idx];

    //     int pick = nums[idx]+f(idx-2,nums,dp);
    //     int notpick = f(idx-1,nums,dp);

    //     return dp[idx] = max(pick,notpick);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        // return f(n-1,nums,dp); memoization
        // tabulation
        // dp[0] = nums[0];
        // for(int i=1;i<n;i++){
        //     int pick = nums[i];
        //     if(i>1) pick += dp[i-2];
        //     int notpick = dp[i-1];

        //     dp[i] = max(pick,notpick);
        // }

        // return dp[n-1];

        // space optimization
        int prev = nums[0];
        int prev2 = 0;
        if(nums.size()==1) return nums[0];
        int curr;
        for(int i=1;i<n;i++){
        int pick = nums[i];
        if(i>1) pick += prev2;
        int notpick = prev;
        curr = max(pick,notpick);

        prev2 = prev;
        prev = curr;
    }
     return curr;
    }
   
};