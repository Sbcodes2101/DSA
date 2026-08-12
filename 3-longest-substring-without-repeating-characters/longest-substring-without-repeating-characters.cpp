class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;int j=0;
        int len = INT_MIN;
        unordered_map<char,int> mp;
        while(j<n){
            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }

            len = max(len,j-i+1);
            mp[s[j]]=j;
            j++;
        }

        return (len==INT_MIN)? 0:len;
    }
};