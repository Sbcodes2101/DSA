class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int hash[26] = {0};
        int maxifreq = INT_MIN;
        int ans = 0;

        while(j<n){
            hash[s[j]-'A']++;
            maxifreq = max(maxifreq,hash[s[j]-'A']);

            while((j-i+1)-maxifreq > k){
                hash[s[i]-'A']--;
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};