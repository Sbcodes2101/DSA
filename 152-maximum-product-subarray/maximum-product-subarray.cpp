class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int productf = 1;
        int productb = 1;
        int maxi=INT_MIN;
        for(int i =nums.size()-1; i>=0; i--){
            if(productf==0) productf=1;
            if(productb==0) productb=1;
            productf *= nums[i];
            productb *= nums[n-1-i];
            maxi = max(maxi,max(productb,productf));
        }
        return maxi;
    }
};