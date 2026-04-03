class Solution {
public:
    // int f(string &s,int idx,vector<int> &dp){
    //     if(idx==s.size()){
    //         return 1;
    //     }
    //     if(s[idx]=='0') return 0;
    //     if(dp[idx]!=-1) return dp[idx];

    //     int only_one_char = f(s,idx+1,dp);
    //     int only_two_char = 0;

    //     if(idx+1<s.size()) {if(s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6'))
    //     {only_two_char = f(s,idx+2,dp);}}

    //     return dp[idx] = only_one_char+only_two_char;
    // }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        // return f(s,0,dp);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') dp[i] = 0;
            else{
                dp[i] += dp[i+1];
                if(i+1<n){
                    if(s[i]=='1' || s[i]=='2' && s[i+1]<='6'){
                        dp[i] += dp[i+2];
                    }
                }
            }
        }
        return dp[0];
    }
};