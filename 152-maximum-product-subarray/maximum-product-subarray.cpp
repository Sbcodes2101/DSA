class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int productf = 1;
        int productl = 1;
        for(int i=0;i<n;i++){
            if(productf==0) productf=1;
            if(productl==0) productl=1;
            productf *= nums[i];
            productl *= nums[n-i-1];
            ans = max(ans,max(productf,productl));
        }
        return ans;
    }
};