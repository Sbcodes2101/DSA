class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        // brute force
        // int n=arr.size();
        // int ans=k;
        // for(int i=0;i<n;i++){
        //     if(arr[i]<=ans) ans++;
        //     else break;
        // }
        // return ans;

        // binary search approach
        int lo=0;
        int hi=n-1;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            int missing = arr[mid]-(mid+1);
            if(missing < k){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return k+hi+1;
    }
};