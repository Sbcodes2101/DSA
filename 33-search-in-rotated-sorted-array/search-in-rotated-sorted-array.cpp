class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        if(n==1) return (nums[0]==target)? 0:-1;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;

            if(nums[mid]>=nums[lo]){// left side is sorted
                if(target>=nums[lo] && target<nums[mid]){
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            if(nums[mid]<=nums[hi]){// right side is sorted
                if(target>nums[mid]&&target<=nums[hi]){
                    lo =mid+1;
                }
                else hi = mid-1;
            }
        }

        return -1;
    }
}; 