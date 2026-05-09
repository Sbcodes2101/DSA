class Solution {
public:
    long long hrs(int mid,vector<int> &piles){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans += ceil((double)piles[i]/mid);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int hi = *max_element(piles.begin(),piles.end());
        int lo = 1;
        int ans = hi;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            long long totalhr  = hrs(mid,piles);
            if(totalhr<=h){
                ans = mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};