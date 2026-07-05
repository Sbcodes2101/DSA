class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int ans = INT_MIN;
        int sum=0;

        for(j=0;j<k;j++){
            sum += nums[j];
        }

        ans = max(ans,sum);

        while(j<n){
            sum += nums[j];
            sum -= nums[i];
            i++;
            j++;
            ans = max(ans,sum);
        }

        return ((double)ans/(double)k);
    }
};