class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prevHeight(n);
        prevHeight[0] = height[0];
         
        for(int i=1;i<n;i++){
            prevHeight[i] = max(prevHeight[i-1],height[i]);
        }

        vector<int> nxtHeight(n);
        nxtHeight[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            nxtHeight[i] = max(nxtHeight[i+1],height[i]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(height[i]<prevHeight[i] && height[i]<nxtHeight[i]){
            ans += min(prevHeight[i],nxtHeight[i])-height[i];
            }
        }

        return ans;
    }
};