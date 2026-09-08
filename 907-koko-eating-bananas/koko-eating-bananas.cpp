class Solution {
public:
    long long f(int speed,vector<int>& piles){
        long long ans  = 0;

        for(int i=0;i<piles.size();i++){
            ans += ceil((double)piles[i]/speed);
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int final_ans = hi;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            long long ans = f(mid,piles);

            if(ans<=h){
                final_ans = min(final_ans,mid);
                hi = mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        return final_ans;
    }
};