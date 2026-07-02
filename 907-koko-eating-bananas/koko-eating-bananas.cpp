class Solution {
public:
    long long calchr(int mid, vector<int> &piles){
        int n = piles.size();
        long long hr=0;
        for(int i=0;i<n;i++){
            hr += ceil((double)piles[i]/mid);
        }

        return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int ans=hi;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            long long total_hr = calchr(mid,piles);

            if(total_hr<=h){
                ans = min(ans,mid);
                hi=mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};