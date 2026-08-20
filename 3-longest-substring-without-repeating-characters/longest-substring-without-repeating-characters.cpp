class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;int j=0;
        int maxLen = 0;
        unordered_map<int,int> mp;

        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                if(mp[s[j]]>=i){
                    i = mp[s[j]]+1;
                }
            }

            maxLen = max(maxLen,j-i+1);
            mp[s[j]] = j;
            j++;
        }

        return maxLen;
    }
};