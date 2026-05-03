class Solution {
  public:
    long long f(int mid,int n){
        long long ans = 1;
        for(int j=0;j<n;j++){
            ans *= mid;
        }
        return ans;
    }
    
    int nthRoot(int n, int m) {
        // Code here
        int lo=0;
        int hi=m;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            if(f(mid,n) == (long long)m) return mid;
            else if(f(mid,n)>(long long)m) hi=mid-1;
            else lo=mid+1;
        }
        
        return -1;
    }
};