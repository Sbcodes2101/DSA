class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxlen=0;
        // for(int i=0;i<s.size();i++){
        //     int hash[256] = {0};
        //     for(int j=i;j<s.size();j++){
        //         if(hash[s[j]]==1) break;
        //         int len = j-i+1;
        //         maxlen = max(maxlen,len);
        //         hash[s[j]] = 1;
        //     }
        // }
        vector<int> hash(256,-1);
        int l=0;
        int r=0;
        int maxlen = 0;
        if(s.size()==1) return 1;
        while(r<s.size()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l)
               {l = hash[s[r]]+1;}
            }
            int len = r-l+1;
            maxlen = max(maxlen,len);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};