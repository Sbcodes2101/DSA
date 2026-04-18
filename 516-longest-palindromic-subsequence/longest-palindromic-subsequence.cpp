class Solution {
public:
    int solve(string &s,string &s1,int i,int j,vector<vector<int>> &dp){
        if(i>=s.length() || j>=s1.length()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s1[j]){
            return dp[i][j] = 1+solve(s,s1,i+1,j+1,dp);
        }
        return dp[i][j] = max(solve(s,s1,i+1,j,dp),solve(s,s1,i,j+1,dp));
    }

    int longestPalindromeSubseq(string s) {
        string curr=s;
        reverse(curr.begin(),curr.end());
        vector<vector<int>> dp(s.size(),vector<int> (s.size(),-1));
        return solve(s,curr,0,0,dp);
    }
};