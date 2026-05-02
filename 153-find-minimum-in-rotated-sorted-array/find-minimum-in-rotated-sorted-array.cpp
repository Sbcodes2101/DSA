class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo=0;
        int hi=n-1;
        int ans=INT_MAX;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            
            // pivot point will always be on the non sorted half
            // left half is sorted therefore we pick the minimum
            // from the sorted half and move towards right
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