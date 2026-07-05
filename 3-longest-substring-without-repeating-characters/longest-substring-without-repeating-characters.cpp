class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi=0; 

        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=i;j<n;j++){
                char ch = s[j];
                if(st.find(ch)!=st.end()){
                    break;
                }

                st.insert(ch);
                maxi = max(j-i+1,maxi);
            }
        }

        return maxi;
    }
};