class Solution {
public:
    int f(int idx,string &s,vector<int> &dp){
        if (idx==s.size()){
            return 1;
        }

        if(s[idx]=='0') return 0;

        if(dp[idx]!=-1) return dp[idx];

        int result = f(idx+1,s,dp);

        if(idx+1<s.size())
        {
            if(s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6'))
            {
            result += f(idx+2,s,dp);
            }
        } 

        return dp[idx] = result;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }
};