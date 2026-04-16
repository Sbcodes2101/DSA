class Solution {
public:
    int f(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i>=s1.length() || j>=s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+f(s1,s2,i+1,j+1,dp);
        }
        return dp[i][j] = max(f(s1,s2,i+1,j,dp),f(s1,s2,i,j+1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1));
        // return f(text1,text2,0,0,dp);
        int n=text1.size();
        int m=text2.size();
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }

        for(int j=0;j<m;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }

               else { dp[i][j] = max(dp[i-1][j],dp[i][j-1]);}
            }
        }

        return dp[n][m];
    }
};