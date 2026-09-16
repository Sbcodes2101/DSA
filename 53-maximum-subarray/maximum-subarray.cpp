class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum>0){
                maxi = max(maxi,sum);
            }
            else{
                maxi = max(maxi,sum);
                sum=0;
            }
        }
        return (maxi==INT_MIN)? 0:maxi;
    }
};