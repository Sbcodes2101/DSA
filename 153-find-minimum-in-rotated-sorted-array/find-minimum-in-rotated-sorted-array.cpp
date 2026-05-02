class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo=0;
        int hi=n-1;
        int ans=INT_MAX;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            
            if(nums[mid]>=nums[lo]){
                ans = min(ans,nums[lo]);
                lo = mid+1;
            }

            else if(nums[hi]>=nums[mid]){
                ans = min(ans,nums[mid]);
                hi=mid-1;
            }
        }

        return ans;
    }
};