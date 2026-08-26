class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size(); 
        stack<int> st;

        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int first_ele = st.top();
                st.pop();
                int second_ele = st.top();
                st.pop();

                if(tokens[i]=="+"){
                    st.push(first_ele + second_ele);
                }

                else if(tokens[i]=="-"){
                    st.push(second_ele-first_ele);
                }

                else if(tokens[i]=="*"){
                    st.push(second_ele*first_ele);
                }

                else{
                    st.push(second_ele/first_ele);
                }
            }

            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};