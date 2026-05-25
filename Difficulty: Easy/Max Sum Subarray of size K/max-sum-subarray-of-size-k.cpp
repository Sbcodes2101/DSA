class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum=0;
        int maxSum=INT_MIN;
        int l=0;
        int r=0;
        while(r<n){
            int len = r-l+1;
            while(len>k){
                sum -= arr[l];
                l++;
                len=r-l+1;
            }
            
            sum += arr[r];
            maxSum = max(maxSum,sum);
            r++;
        }
        
        return maxSum;
    }
    
};