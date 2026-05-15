class Solution {
public:
    int f(string &s,int idx,vector<int> &dp){
        if(idx==s.size()){
            return 1;
        }

        if(dp[idx]!=-1) return dp[idx];

        if(s[idx]=='0') return 0;

        int pick_one_char = f(s,idx+1,dp);
        int pick_two_char = 0;

        if(idx+1<s.size()){
            if(s[idx]=='1' || s[idx]=='2' && s[idx+1]<='6'){
                pick_two_char = f(s,idx+2,dp);
            }
        }

        return dp[idx] = pick_one_char+pick_two_char;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(s,0,dp);
    }
};