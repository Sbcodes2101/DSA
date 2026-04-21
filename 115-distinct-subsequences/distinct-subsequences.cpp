class Solution {
public:
    long long solve(string &s,string &t,int i,int j,vector<vector<long long>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
        }
        return dp[i][j]=solve(s,t,i-1,j,dp);
    }

    int numDistinct(string s, string t){
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1,0),curr(m+1,0);
        // return (int)solve(s,t,n-1,m-1,dp);
        prev[0]=1;
        curr[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1]+prev[j];
                else{
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};