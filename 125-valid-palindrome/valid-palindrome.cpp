class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string curr = "";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                curr += tolower(s[i]);
            }
        }

        int i=0;int j=curr.size()-1;

        while(j>=i){
            if(curr[i]!=curr[j]) return false;
            i++;j--;
        }

        return true;
    }
};