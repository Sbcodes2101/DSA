class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int days){
        int count=0;
        int noOfB=0;
        int n=bloomDay.size();

        for(int i=0;i<n;i++){
            if(bloomDay[i] <= days){
                count++;
            }
            else{
                noOfB += count/k;
                count=0;
            }
        }

        noOfB += count/k;
        if(noOfB >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>(long long)n) return -1;
        int lo = *min_element(bloomDay.begin(),bloomDay.end());
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = hi;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            if(check(bloomDay,m,k,mid)==true) {
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};