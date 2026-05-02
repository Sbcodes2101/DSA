class Solution {
  public:
    int lowerB(vector<int> &arr,int x){
        int lo=0;
        int hi=arr.size()-1;
        int ans = arr.size();
        while(hi>=lo){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid]>=x){
                ans = mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        return ans;
    }
    
    int upperB(vector<int> &arr,int x){
        int lo=0;
        int hi=arr.size()-1;
        int ans = arr.size();
        while(hi>=lo){
            int mid = lo + (hi - lo) / 2;
            if(arr[mid]>x){
                ans = mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        return ans;
    }
    
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int lb = lowerB(arr,x);
        if(lb==arr.size() || arr[lb]!=x) return {-1,-1};
        int ub = upperB(arr,x);
        return {lb,ub-1};
    }
};