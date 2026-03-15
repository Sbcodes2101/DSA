class Solution {
  public:
  
    bool printS(int n,vector<int> &arr,int k,int &sum,int idx){
        if(sum>k) return false;
        if(idx == n){
            if(sum == k) return true;
            else return false;
        }
        
        sum += arr[idx];
        if(printS(n,arr,k,sum,idx+1) == true) return true;
        
        sum -= arr[idx];
        if(printS(n,arr,k,sum,idx+1) == true) return true;
         
        return false;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        int sum=0;
        return printS(n,arr,k,sum,0);
    }
};