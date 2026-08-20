class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;int j=0;
        int maxLen = 0;
        unordered_map<int,int> mp;

        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                while(mp.find(s[j])!=mp.end()){
                mp.erase(s[i]);
                i++;
                }
            }

            maxLen = max(maxLen,j-i+1);
            mp[s[j]] = j;
            j++;
        }

        return maxLen;
    }
};