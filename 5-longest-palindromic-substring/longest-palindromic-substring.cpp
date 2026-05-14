class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        string result = "";
        int maxlen = 0;

        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j){
                    dp[i][j]=true;

                }

                else if(i+1==j){
                    if(s[i]==s[j]){
                    dp[i][j] = (s[i]==s[j]);
                    }
                }

                else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                    }

                    if(dp[i][j] && L>maxlen){
                        maxlen = L;
                        result = s.substr(i,L);
                    }
                }
                
            }
            return result;
        }
};