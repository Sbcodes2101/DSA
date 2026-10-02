class Solution {
public:
    void f(int n,int oc,int cc,string s,vector<string> &ans){
        if(cc==n){
            ans.push_back(s);
            return;
        }

        if(oc<n) f(n,oc+1,cc,s+'(',ans);
        if(oc>cc) f(n,oc,cc+1,s+')',ans);

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0;
        int cc = 0;
        string s = "";
        f(n,oc,cc,s,ans);
        return ans;
    }
};