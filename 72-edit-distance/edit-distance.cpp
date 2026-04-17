class Solution {
public:
    int solve(string &words1,string &words2,int i,int j,vector<vector<int>> &dp){
        if(i==words1.size()){
            return words2.size()-j;
        }
        if(j==words2.size()){
            return words1.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(words1[i]==words2[j]) return solve(words1,words2,i+1,j+1,dp);
        int insert = 1+solve(words1,words2,i,j+1,dp);
        int del = 1+solve(words1,words2,i+1,j,dp);
        int replace = 1+solve(words1,words2,i+1,j+1,dp);
        return dp[i][j]=min(insert,min(del,replace));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1));
        // return solve(word1,word2,0,0,dp);
        int n=word1.size();
        int m=word2.size();

        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = 1+dp[i][j-1];
                    int del = 1+dp[i-1][j];
                    int replace = 1+dp[i-1][j-1];

                    dp[i][j] = min({insert,del,replace});
                }
            }
        }

        return dp[n][m];
    }
};