class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        int r=0;
        int no_of_zeroes=0;
        int maxlen=0;
        while(r<n){
           if(nums[r]==0) no_of_zeroes++;
           while(no_of_zeroes>k){
            if(nums[l]==0) no_of_zeroes--;
            l++;
           }
           maxlen = max(maxlen,r-l+1);
           r++;
        }
        return maxlen;
    }
};