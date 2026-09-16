class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true; 

        int max_reachable = 0;

        for(int i=0;i<n;i++){
            if(i>max_reachable) return false;
            if(i+nums[i]>=n) return true;
            else{
                max_reachable = max(max_reachable,i+nums[i]);
            }
        }

        return (max_reachable==n-1)? true:false;
    }
};