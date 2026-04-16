class Solution {
  public:
    // int f(vector<int>& arr,int idx,int prev_idx){
    //     if(idx==arr.size()) return 0;
        
    //     int pick = INT_MIN;
    //     int not_pick=0+f(arr,idx+1,prev_idx);
    //     if(prev_idx==-1 || arr[idx]>arr[prev_idx]){
    //         pick = 1+f(arr,idx+1,idx);
    //     }
        
    //     return max(pick,not_pick);
    // }
    
    int lis(vector<int>& arr) {
        // code here
        // return f(arr,0,-1);
        int n=arr.size();
        vector<int> dp(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                   dp[i] = max(dp[i],dp[j]+1);
                   maxlen = max(maxlen,dp[i]);
                }
            }
        }
        return maxlen;
    }
};