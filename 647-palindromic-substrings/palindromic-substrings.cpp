class Solution {
public:
    bool check(int i,int j,string s,vector<vector<int>> &dp){
        if(i>j){
           return true; 
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j] = check(i+1,j-1,s,dp);
        }

        return dp[i][j]=false;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<bool>> dp(n,vector<bool> (n,false));

        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(check(i,j,s,dp)){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j = i+L-1;
                if(i == j){
                    dp[i][j] = true;
                }

                else if(i+1 == j){
                    dp[i][j] = (s[i]==s[j]);
                }

                else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]==true){
                    count++;
                }
            
            }
        }

        return count;
    }
};