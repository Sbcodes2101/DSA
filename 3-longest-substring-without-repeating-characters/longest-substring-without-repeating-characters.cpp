class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;int r=0;
        int maxlen = INT_MIN;
        if(s.size()==0) return 0;
        unordered_map<char,int> mp;

        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                    l = mp[s[r]]+1;
                }
            }

            maxlen = max(maxlen,r-l+1);
            mp[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};