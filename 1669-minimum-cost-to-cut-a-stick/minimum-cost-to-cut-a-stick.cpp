class Solution {
public:
    int f(vector<int> &scale,int left,int right,vector<vector<int>> &dp){
        if(left+1==right) return 0;

        if(dp[left][right]!=-1) return dp[left][right];

        int cost = INT_MAX;
    
        for(int i=left+1;i<right;i++){
            int ans = scale[right]-scale[left];
            ans += f(scale,left,i,dp);
            ans += f(scale,i,right,dp);
            cost = min(cost,ans);
        }

        return dp[left][right] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int> scale;
        scale.push_back(0);

        for(int i=0;i<cuts.size();i++){
            scale.push_back(cuts[i]);
        }

        scale.push_back(n);

        vector<vector<int>> dp(scale.size(),vector<int> (scale.size(),-1));
        
        return f(scale,0,scale.size()-1,dp);
    }
};