class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxfreq = 0;
        int hash[26] = {0};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            int changes = r-l+1-(maxfreq);
            if(changes>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(changes<=k) maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};