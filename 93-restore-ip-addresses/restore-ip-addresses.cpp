class Solution {
public:
    bool isValid(string str){
        if(str[0]=='0') return false;

        int val = stoi(str);
        return val<=255;
    }
    void solve(int idx,vector<string> &ans,string curr,int parts,string &s){
        int n=s.length();
        if(idx == s.length() && parts==4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if(idx+1<=s.length()){
            solve(idx+1,ans,curr+s.substr(idx,1)+'.',parts+1,s);
        }

        if(idx+2<=s.length() && isValid(s.substr(idx,2))){
            solve(idx+2,ans,curr+s.substr(idx,2)+'.',parts+1,s);
        }

        if(idx+3<=s.length() && isValid(s.substr(idx,3))){
            solve(idx+3,ans,curr+s.substr(idx,3)+'.',parts+1,s);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length()>12) return {};

        int parts=0;
        string curr="";
        solve(0,ans,curr,parts,s);
        return ans;
    }
};