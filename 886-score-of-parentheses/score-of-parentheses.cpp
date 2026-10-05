class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<char> st;
        int multiplier = 1;
        int count = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                multiplier *= 2;
            }

            else{
                if(!st.empty() && s[i]==')'){
                    multiplier = multiplier/2;
                    if(s[i-1]=='('){
                        count += multiplier;
                    }
                    
                    st.pop();
                }
            }
        }

        return count;
    }
};