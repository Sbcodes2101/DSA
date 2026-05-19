class Solution {
public:
    int f(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]){
           return dp[i][j] = 1 + f(text1,text2,i+1,j+1,dp);
        }

        return dp[i][j] = max(f(text1,text2,i+1,j,dp),f(text1,text2,i,j+1,dp));

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return f(text1,text2,0,0,dp);

        for(int i=1;i<text1.size()+1;i++){
            for(int j=1;j<text2.size()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};