class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]){
            return dp[i][j] = solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
        }

        return dp[i][j] = solve(s,t,i-1,j,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return 0;
        // vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        // return solve(s,t,n,m,dp);

        // for(int i=0;i<=n;i++){
        //     dp[i][0] = 1;
        // }

        vector<unsigned long long> prev(m+1,0);
        prev[0]=1;

        for(int i=1;i<=n;i++){
            vector<unsigned long long> curr(m+1,0);
            curr[0]=1;
            for(int j=1;j<=m;j++){ 
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1]+prev[j];
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};