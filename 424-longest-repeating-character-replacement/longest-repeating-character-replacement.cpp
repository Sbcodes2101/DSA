class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_Len = INT_MIN;
        int hash[26] = {0};

        int i=0;
        int j=0;

        int max_freq = 0;

        while(j<n){
            int freq = ++hash[s[j]-'A'];

            if(freq>max_freq){
                max_freq = freq;
            }

            if((j-i+1)-max_freq<=k){
                max_Len = max(max_Len,j-i+1);
            }

            else{
                while((j-i+1)-max_freq>k){
                    hash[s[i]-'A']--;
                    i++;
                }
            }

            j++;
        }

        return max_Len;
    }
};