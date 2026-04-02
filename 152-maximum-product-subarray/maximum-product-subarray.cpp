class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int productf = 1;
        int productb = 1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(productf==0) productf=1;
            if(productb==0) productb=1;
            productf *= nums[i];
            productb *= nums[n-i-1];
            maxi = max(maxi,max(productb,productf));
        }
        return maxi;
    }
};