class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> frontLIS(n,1);
        vector<int> rearLIS(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    frontLIS[i] = max(frontLIS[i],1+frontLIS[j]);
                }
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    rearLIS[i] = max(rearLIS[i],1+rearLIS[j]);
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(frontLIS[i]!=1 && rearLIS[i]!=1){
                ans = max(ans,frontLIS[i]+rearLIS[i]-1);
            }
        }
        
        return ans;
    }
};
