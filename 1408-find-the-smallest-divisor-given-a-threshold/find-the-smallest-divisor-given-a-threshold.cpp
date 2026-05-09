class Solution {
public:
    int f(vector<int> &nums,int threshold,int mid){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += ceil((double)nums[i]/mid);
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int hi = *max_element(nums.begin(),nums.end());
        int lo = 1;
        int ans=hi;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            int min_div = f(nums,threshold,mid);
            if(min_div <= threshold){
                ans=mid;
                hi = mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};