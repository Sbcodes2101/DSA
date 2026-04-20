class Solution {
public:
    int characterReplacement(string s, int k) {
    //    Brute Force
    //    int n = s.size();
    //    int maxlen = 0;
    //    for(int i=0;i<n;i++){
    //     int hash[26] = {0};
    //     int maxfreq=0;
    //         for(int j=i;j<n;j++){
    //             hash[s[j]-'A']++;
    //             maxfreq = max(maxfreq,hash[s[j]-'A']);
    //             int changes = (j-i+1)-maxfreq;
    //             if(changes<=k){
    //                 maxlen = max(maxlen,j-i+1);
    //             }
    //         }
    //     }
    //     return maxlen;

    int n=s.size();
    int maxlen=0;
    int l=0;int r=0;
    int hash[26] = {0};
    int maxfreq = 0;
        while(r<n){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            int changes = (r-l+1)-maxfreq;
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