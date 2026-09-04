class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n+1,1);

        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]) LIS[i] = max(LIS[i],1+LIS[j]);
                ans = max(ans,LIS[i]);
            }
        }

        return (ans==INT_MIN)? 1:ans;
    }
};