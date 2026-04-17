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
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),-1));
        return solve(word1,word2,0,0,dp);
    }
};