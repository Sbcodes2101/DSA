class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> maxSum(n,0);
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            maxSum[i] = arr[i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    maxSum[i] = max(maxSum[i],maxSum[j]+arr[i]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            ans = max(ans,maxSum[i]);
        }
        
        return ans;
    }
};