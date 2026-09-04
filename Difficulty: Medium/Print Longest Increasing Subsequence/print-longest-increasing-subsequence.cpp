class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> LIS(n,1);
        vector<int> parent(n,-1);
        
        vector<int> ans1;
        int ans = 1;
        int idx = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && LIS[i]<LIS[j]+1) {
                    LIS[i] = 1+LIS[j];
                    parent[i] = j;
                }
            }
            
            if(ans<LIS[i]){
                ans = LIS[i];
                idx = i;
            }
        }
        
        
        while(idx != -1){
            ans1.push_back(arr[idx]);
            idx = parent[idx];
        }
        
        reverse(ans1.begin(),ans1.end());
        
        return ans1;
    }
};