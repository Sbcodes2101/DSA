class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int ans = arr.size();
        int lo = 0;
        int hi = arr.size()-1;
        while(hi>=lo){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]>target){
                ans = mid;
                hi = mid-1;;
            }
            else lo = mid+1;
        }
        return ans;
    }
};
