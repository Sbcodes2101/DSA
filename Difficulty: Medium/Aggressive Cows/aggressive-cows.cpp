class Solution {
  public:
    bool canWePlace(vector<int> &stalls,int k,int dist){
        int cows=1;
        int lastcow=stalls[0];
        int n=stalls.size();
        for(int i=1;i<n;i++){
            if(stalls[i]-lastcow>=dist){
                cows++;
                lastcow=stalls[i];
            }
        }
        if(cows>=k) return true;
        else return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int lo=0;
        int hi=stalls[n-1]-stalls[0];
        int ans=-1;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(canWePlace(stalls,k,mid)==true){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};