class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        // int n = arr.size();
        // int ans = INT_MIN;
        
        // for(int i=0;i<=n-k;i++){
        //     int sum=0;
        //     for(int j=i;j<i+k;j++){
        //         sum = sum+arr[j];
        //     }
        //     ans = max(ans,sum);
        // }
        
        // return ans;
        
        int n = arr.size();
        int ans = 0;
        int sum=0;
        int j=0;
        int i=0;
        
        for(j=0;j<k;j++){
            sum += arr[j];
        }
        
        ans = max(ans,sum);
        
        while(j<n){
            sum += arr[j];
            sum -= arr[i];
            i++;
            j++;
            ans = max(ans,sum);
        }
        
        return ans;
    }
};