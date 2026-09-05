class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);
        vector<int> count(n,1);

        int maxLen = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(LIS[i]<LIS[j]+1){
                        LIS[i] = LIS[j]+1;
                        count[i] = count[j];
                    }
                    else if(LIS[i]==LIS[j]+1){
                        count[i] += count[j];
                    }
                }
            }

            if(maxLen<LIS[i]){
                maxLen = LIS[i];
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(LIS[i]==maxLen){
                ans += count[i];
            }
        }

        return ans;
    }
};