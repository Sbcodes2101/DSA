class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s.length()==0) return 0;
        int maxlen = INT_MIN;
        for(int i=0;i<n;i++){
            int hash[256] = {0};
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1){
                    break;
                }
                maxlen=max(maxlen,j-i+1);
                hash[s[j]]=1;
            }
        }
        return maxlen;
    }
};