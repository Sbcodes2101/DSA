class Solution {
  public:
    int f(int n,int m,string &s1,string &s2,int &result,vector<vector<int>> &dp){
        if(n==0 || m==0) return 0;

        if(dp[n][m]!=-1) return dp[n][m];

        int answer = 0;
        if(s1[n-1]==s2[m-1]){
            answer = 1+f(n-1,m-1,s1,s2,result,dp);
            result = max(result,answer);
        }


        f(n-1,m,s1,s2,result,dp);
        f(n,m-1,s1,s2,result,dp);

        return dp[n][m] = answer;
    }

    int longCommSubstr(string& s1, string& s2) {
       int n = s1.size();
       int m = s2.size();
       int result = 0;
       vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
       f(n,m,s1,s2,result,dp);
       return result;
    }
};