class Solution {
public:
    bool isPalindrome(string s,int idx,int i){
        while(idx<=i){
            if(s[i--]!=s[idx++]) return false;
        }
        return true;
    }

    void solve(int idx,string s,vector<vector<string>> &ans,vector<string> ans1){
        if(idx==s.size()){
            ans.push_back(ans1);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                ans1.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,ans,ans1);
                ans1.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ans1;
        solve(0,s,ans,ans1);
        return ans;
    }
};