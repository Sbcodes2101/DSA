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
        vector<int> dp(n,0);
        // // return f(nums,dp,n-1);

        // dp[0] = nums[0];
        // for(int i=1;i<n;i++){
        //     int pick = nums[i];
        //     if(i>1) pick+= dp[i-2];
        //     int not_pick = dp[i-1];

        //     dp[i] = max(pick,not_pick);
        // }

        // return dp[n-1];

        // space optimization

        int prev = nums[0];
        int prev2=0;
        int curr;
        if(nums.size()==1) return nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int not_pick = prev;

            curr = max(pick,not_pick);

            prev2=prev;
            prev = curr;
        }

        return curr;
    }
};