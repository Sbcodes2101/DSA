class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s.length()==0) return 0;
        if(s==" ") return 1;
        int maxlen = INT_MIN;
        // for(int i=0;i<n;i++){
        //     int hash[256] = {0};
        //     for(int j=i;j<n;j++){
        //         if(hash[s[j]]==1){
        //             break;
        //         }
        //         maxlen=max(maxlen,j-i+1);
        //         hash[s[j]]=1;
        //     }
        // }
        // return maxlen;

        int l=0;int r=0;
        vector<int> hash(256, -1);
        while(r<n){
            if(hash[s[r]]!=-1){
                if(l <= hash[s[r]]){
                    l = hash[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxlen = max(maxlen,len);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};