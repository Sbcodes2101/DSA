class Solution {
public:
    int findKRotation(vector<int> &nums) {
       int lo=0;
       int hi=nums.size()-1;
       int idx = -1;
       int ans = INT_MAX;
       while(hi>=lo){
           int mid = lo+(hi-lo)/2;
           if(nums[mid]>=nums[lo]){
               if(ans>nums[lo]){
                   ans = nums[lo];
                   idx = lo;
               }
               lo=mid+1;
           }
           
           else if(nums[hi]>=nums[mid]){
               if(ans>nums[mid]){
                   ans = nums[mid];
                   idx =mid;
               }
               hi=mid-1;
           }
        }
        
        return idx;
    }
};
