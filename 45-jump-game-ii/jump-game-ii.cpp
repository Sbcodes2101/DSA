class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int current_end = 0;
        int maxReach = 0;

        for(int i=0;i<n;i++){
            if(i>current_end){
                jumps++;
                current_end = maxReach;
            }
            maxReach = max(maxReach,nums[i]+i);
        }

        return jumps;
    }
};