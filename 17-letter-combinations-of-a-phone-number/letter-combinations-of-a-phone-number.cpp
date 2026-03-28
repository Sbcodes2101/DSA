class Solution {
public:
    void solve(int idx,map<char,string> &mp,vector<string> &ans,string digits,string &temp){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string s = mp[ch];
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            solve(idx+1,mp,ans,digits,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        vector<string> ans;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp;
        solve(0,mp,ans,digits,temp);
        return ans;
    }
};