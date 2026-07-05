class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // int maxi=0; 

        // for(int i=0;i<n;i++){
        //     unordered_set<char> st;
        //     for(int j=i;j<n;j++){
        //         char ch = s[j];
        //         if(st.find(ch)!=st.end()){
        //             break;
        //         }

        //         st.insert(ch);
        //         maxi = max(j-i+1,maxi);
        //     }
        // }

        // return maxi;

        int n=s.size();
        int ans = INT_MIN;
        int i=0;
        int j=0;
        unordered_set<int> st;

        while(j<n){
            if(st.find(s[j])!=st.end()){
                while(st.find(s[j])!=st.end()){
                    st.erase(s[i]);
                    i++;
                }
            }

            st.insert(s[j]);
            ans = max(ans,j-i+1);
            j++;
        }

        return (ans==INT_MIN)? 0:ans;
    }
};