class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n,vector<bool> (n,0));

        for(int i=0;i<n;i++){
            isPalindrome[i][i] = 1;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j = i+l-1;

                if(s[i]==s[j] && (l==2 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = 1;
                }
            }
        }

        vector<int> dp(n,1e9);
        dp[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n;j++){
                if(isPalindrome[i][j]){
                    if(j==n-1){
                        dp[i]=0;
                    }
                    else dp[i] = min(dp[i],1+dp[j+1]);
                }
            }
        }

        return (dp[0]==1e9)? 1:dp[0];
    }
};